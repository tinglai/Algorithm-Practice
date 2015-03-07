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

public class Normalize
{
	public static class Map extends Mapper<LongWritable, Text, LongWritable, DoubleWritable> {
		private final static LongWritable one = new LongWritable(1);

		public void map(LongWritable key, Text value, Context context)
				throws IOException, InterruptedException {
			String line = value.toString();

			String tfidf_list = (line.split("\\s+", 3))[2];
			
			Long pagid;
			Double tfidf;
			for(String token : tfidf_list.split("\\s+")){
//System.out.println("debug info: token = " + token);
				String[] subTokens = token.split("\\:+");
//System.out.println("debug info: subTokens[0] = " + subTokens[0]);
				pagid = Long.parseLong(subTokens[0]);
				tfidf = Double.parseDouble(subTokens[1]);
				context.write(new LongWritable(pagid), new DoubleWritable(tfidf));
			}
		}
	}

	public static class Reduce extends Reducer<LongWritable, DoubleWritable, LongWritable, DoubleWritable> {
		
		public void reduce(LongWritable key, Iterable<DoubleWritable> values, Context context)
				throws IOException, InterruptedException {
			
			Double denominator = 0.0;
			for (DoubleWritable value : values) {
				denominator += value.get() * value.get();
			}
			denominator = Math.sqrt(denominator);

			context.write(key, new DoubleWritable(denominator));
		}
	}

	public static void main(String[] args) throws Exception
	{
		Configuration conf = new Configuration();

		Job job = new Job(conf, "Normalize");

		job.setOutputKeyClass(LongWritable.class);//pagid
		job.setOutputValueClass(DoubleWritable.class);//tfidf

		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));

		job.waitForCompletion(true);
	}
}
