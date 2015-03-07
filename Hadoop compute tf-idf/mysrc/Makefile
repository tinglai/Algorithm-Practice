all: main

main:
	javac -cp .:../hadoop-core-1.0.1.jar:../lib/* -d bin First.java XmlInputFormat.java
	jar -cvf ./First.jar -C bin/ .
	javac -cp .:../hadoop-core-1.0.1.jar:../lib/* -d bin Idf.java XmlInputFormat.java
	jar -cvf ./Idf.jar -C bin/ .
	javac -cp .:../hadoop-core-1.0.1.jar:../lib/* -d bin Normalize.java 
	jar -cvf ./Normalize.jar -C bin/ .
	javac -cp .:../hadoop-core-1.0.1.jar:../lib/* -d bin Conclude.java 
	jar -cvf ./Conclude.jar -C bin/ .

invindex:
	javac -cp .:../hadoop-core-1.0.1.jar:../lib/* -d bin InvertedIndex.java XmlInputFormat.java
	jar -cvf ./InvertedIndex.jar -C bin/ .

xom:
	javac -cp .:../hadoop-core-1.0.1.jar:../lib/* -d bin XOMtest.java
	java -Xms1024m -Xmx1024m -cp .:../lib/*:bin/ edu.umich.cse.eecs485.XOMtest

clean:
	rm -rf *.jar bin/* output* 
