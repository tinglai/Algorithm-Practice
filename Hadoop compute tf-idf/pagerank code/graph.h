#ifndef GUARD_graph_h
#define GUARD_graph_h

#include <unordered_map>
#include "node.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

class Graph{
private:
	std::unordered_map<int, Node*> allNodes;
	std::unordered_set<int> sinkNodes;
	double d;
	std::string mode;
	int N;//number of nodes
	int iteration;//time of iterations
	double accuracy;
	std::ofstream outStream;
public:
	Graph(){}
	Graph(int, char**);
	void addNode(int, Node*);
	void Kpagerank();
	void Cpagerank();
	~Graph();
};

#endif
