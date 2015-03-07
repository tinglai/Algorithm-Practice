#!/bin/bash

rm -rf proutput
mkdir proutput
make -C pagerank\ code

pagerank\ code/eecs485pa5p 0.85 -k 50 pagerank\ code/mining.edges.xml proutput/pgoutput.txt
