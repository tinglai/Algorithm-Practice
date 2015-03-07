#!/bin/bash

export JAVA_HOME=/usr

../bin/hadoop jar First.jar edu.umich.cse.eecs485.First ../dataset/mining.articles.small.xml output1
../bin/hadoop jar Idf.jar edu.umich.cse.eecs485.Idf ../dataset/mining.articles.small.xml output2
../bin/hadoop jar Normalize.jar edu.umich.cse.eecs485.Normalize ../mysrc/output2/part-r-00000 output3
../bin/hadoop jar Conclude.jar edu.umich.cse.eecs485.Conclude ../mysrc/output2/part-r-00000 output4
