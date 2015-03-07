package edu.umich.cse.eecs485;
//this is the first step: count how many documents in total are there
//I.e to get the variable N

import java.io.IOException;
import java.util.*;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import java.util.HashSet;
import java.util.HashMap;
import nu.xom.*;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.FileInputStream;

public class Conclude
{
	public static HashMap<Long, Double> denominators = new HashMap<Long, Double>();

	public static class Map extends Mapper<LongWritable, Text, Text, Text> {
		public void map(LongWritable key, Text value, Context context)
				throws IOException, InterruptedException {
			String line = value.toString();

			String[] tokens = (line.split("\\s+", 2));
			String word = tokens[0];
			String df_tfidf_list = tokens[1];
			//df_tfidf_list format: df pagid1:tfidf1 pagid2:tfidf2 ...
			
			context.write(new Text(word), new Text(df_tfidf_list));
		}
	}

	public static class Reduce extends Reducer<Text, Text, Text, Text> {
		
		public void reduce(Text key, Iterable<Text> values, Context context)
				throws IOException, InterruptedException {
			for (Text value : values) {
				String[] tempTokens = (value.toString()).split("\\s+", 2);
				String df = tempTokens[0];
				String line = tempTokens[1];
				String invList = " " + df;
				for(String token : line.split("\\s+")){
					//tokens are pagid, tfidf pairs
					String[] subTokens = token.split("\\:");
					Long pagid = Long.parseLong(subTokens[0]);
					Double tfidf = Double.parseDouble(subTokens[1]);
					tfidf = tfidf / denominators.get(pagid);
					invList += " " + subTokens[0] + ":" + String.valueOf(tfidf);
				}
				context.write(key, new Text(invList));
			}
		}
	}

	public static void main(String[] args) throws Exception
	{
		//read the denominators calculated in the normalize step
		Scanner readin = new Scanner(new FileInputStream("/home/laiting/hadoop-example/mysrc/output3/part-r-00000"));
		while(readin.hasNextLine()){
			String line = readin.nextLine();
			String[] tokens = line.split("\\s+");
			Long pagid = Long.parseLong(tokens[0]);
			Double val = Double.parseDouble(tokens[1]);
			denominators.put(pagid, val);
		}

		Configuration conf = new Configuration();

		Job job = new Job(conf, "Normalize");

		job.setOutputKeyClass(Text.class);//word
		job.setOutputValueClass(Text.class);//tfidf_list

		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));

		job.waitForCompletion(true);
	}
}
