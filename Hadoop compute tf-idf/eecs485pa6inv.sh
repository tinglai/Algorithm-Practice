#!/bin/bash

export JAVA_HOME=/usr

rm -rf invoutput
make clean -C hadoop-example/mysrc
make -C hadoop-example/mysrc

hadoop-example/bin/hadoop jar hadoop-example/mysrc/First.jar edu.umich.cse.eecs485.First hadoop-example/dataset/mining.articles.small.xml hadoop-example/mysrc/output1
hadoop-example/bin/hadoop jar hadoop-example/mysrc/Idf.jar edu.umich.cse.eecs485.Idf hadoop-example/dataset/mining.articles.small.xml hadoop-example/mysrc/output2
hadoop-example/bin/hadoop jar hadoop-example/mysrc/Normalize.jar edu.umich.cse.eecs485.Normalize hadoop-example/mysrc/output2/part-r-00000 hadoop-example/mysrc/output3
hadoop-example/bin/hadoop jar hadoop-example/mysrc/Conclude.jar edu.umich.cse.eecs485.Conclude hadoop-example/mysrc/output2/part-r-00000 invoutput
