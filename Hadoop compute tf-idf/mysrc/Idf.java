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
import org.apache.mahout.classifier.bayes.XmlInputFormat;
import java.util.HashSet;
import java.util.HashMap;
import nu.xom.*;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.FileInputStream;

public class Idf
{
	public static Double N;
	public static HashSet<String> stopWords = new HashSet<String>();

	public static class Map extends Mapper<LongWritable, Text, Text, LongWritable> {
		private final static LongWritable one = new LongWritable(1);

		public void map(LongWritable key, Text value, Context context)
				throws IOException, InterruptedException {

			String strId = "";
			String strBody = "";

			// Parse the xml and read data (page id and article body)
			// Using XOM library
			Builder builder = new Builder();

			try {
//				System.out.println(value.toString());
				Document doc = builder.build(value.toString(), null);

				Nodes nodeId = doc.query("//eecs485_article_id");
				strId = nodeId.get(0).getChild(0).getValue();
				
				Nodes nodeBody = doc.query("//eecs485_article_body");
				strBody = nodeBody.get(0).getChild(0).getValue();
			}
			// indicates a well-formedness error
			catch (ParsingException ex) { 
				System.out.println("Not well-formed.");
				System.out.println(ex.getMessage());
			}  
			catch (IOException ex) {
				System.out.println("io exception");
			}
			
			// Tokenize document body
			Pattern pattern = Pattern.compile("\\w+");
			Matcher matcher = pattern.matcher(strBody);
			
			while (matcher.find()) {
				// Write the parsed token
				String word = matcher.group().toLowerCase();
				if(!stopWords.contains(word)){
					context.write(new Text(word), new LongWritable(Integer.valueOf(strId)));
				}
			}
		}
	}

	public static class Reduce extends Reducer<Text, LongWritable, Text, Text> {
		
		public void reduce(Text key, Iterable<LongWritable> values, Context context)
				throws IOException, InterruptedException {
			
			// use a set to keep a set of unique doc IDs
			HashMap<String, Double> tfMap = new HashMap<String, Double>();
			//tfMap is a map with key = docID, and value = tf of the current word in corresponding doc
			
			for (LongWritable value : values) {
				String pagid = String.valueOf(value.get());
				if(!tfMap.containsKey(pagid)){
					tfMap.put(pagid, new Double(1));
				}
				else{
					tfMap.put(pagid, new Double(tfMap.get(pagid) + 1));
				}
			}

			Double idf = Math.log(N / tfMap.size()) / Math.log(10.0);
			
			// Convert the contents of the set into a list
			
			String id_tfidf_list = String.valueOf(tfMap.size());
			Iterator<String> itr = tfMap.keySet().iterator();
			while (itr.hasNext()) {
				String k = itr.next();
				id_tfidf_list += " " + k + ":" + String.valueOf(idf * tfMap.get(k));
			}
			
			context.write(key, new Text(id_tfidf_list));
			//format: word df pagid1:tfidf1 pagid2:tfidf2 ...
		}
	}

	public static void main(String[] args) throws Exception
	{
		//read N calculated in the first step
		Scanner readin = new Scanner(new FileInputStream("/home/laiting/hadoop-example/mysrc/output1/part-r-00000"));
		String line = readin.nextLine();
		String[] tokens = line.split("\\s+");
		//"\\s+" act as a delimiter here meaining to split when accours one or more space
		N = Double.parseDouble(tokens[1]);

		//read the stop words as in PA4
		readin = new Scanner(new FileInputStream("/home/laiting/hadoop-example/dataset/stopWords.txt"));
		while(readin.hasNextLine()){
			line = readin.nextLine();
			stopWords.add(line);
		}

		Configuration conf = new Configuration();

		conf.set("xmlinput.start", "<eecs485_article>");
		conf.set("xmlinput.end", "</eecs485_article>");

		Job job = new Job(conf, "Idf");

		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(LongWritable.class);

		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);

		job.setInputFormatClass(XmlInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));

		job.waitForCompletion(true);
	}
}
