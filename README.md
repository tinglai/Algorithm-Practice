#Group Name:
	Group 71
#Members & contruibution:
	Ting Lai (laiting) 50%
	Jiawei Wang (wangjiaw) 50%

#the invoutput used is in indexServer is in follwoing directory:
	./files_from_pa4/pa4_CPP/invValues.txt
#the proutput  used in indexServer is in following directory:
	./files_from_pa4/pa4_CPP/pagerankValues.txt

#the dataset directory is as follows:
	./hadoop-example/dataset

#Our front end web address is:
	http://eecs485-08.eecs.umich.edu:5671/rjyohh/pa6/search

#Structure of database:
	group71pa2
	table1: PageUrl
	table2: Category
	table3: Image
	table4: InfoBox

###Note:(other details)
        1. We used C++ in indexServer building, Java in indexer (i.e mapreduce)
        2. When clone this repo, please use ssh form instead of HTMLs form since the later one might
        encounter some issues.
	3. We set the default w = 0.80
	4. For some word, the info box is missing due to the provided XML file

#Structure of the githup root
        files_from_pa4: contains the code for building indexServer

        hadoop-example: contains the code for building indexer using Hadoop framework. Most code can
                        be found in /mysrc folder

        pagerank code:  contains the code for calculating pageRank of the docs. We put the mining.edges.xml
                        into the folder for convience

        php:            contains the layout of the webpage as well as the php setup

        crate_tbl.sql & drop_tbl.sql: script for building MySQL database

        eecs485pa6inv.sh: bash script for calculating inverted index with tfidf. the result will be found under
                          a new folder called "invoutput" under the root. The file is called part-r-00000

        eecs485pa6pr.sh: bash script for calculating pagerank. the result will be found under a new folder called
                         "proutput". The file is called proutput.txt


