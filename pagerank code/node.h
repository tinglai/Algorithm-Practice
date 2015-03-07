#ifndef GUARD_node_h
#define GUARD_node_h

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
//#include "graph.h"

class Node{
private:
	double rank = 0;
	double oldRank = 0;
	//std::string label;
	std::vector<int> income;//store the ids of the income nodes
	//std::vector<int> output;//store the ids of the output nodes
	int outPutSize = 0;

public:
	Node(){}
	//Node(double r, std::string l):rank(r), oldRank(r), label(l){}
	Node(double r):rank(r), oldRank(r){}
	void addIncome(int);
	//void addOutput(int);
	void addOutput();
	int getOutputSize();
	double getRank();
	double getOldRank();
	void updateRank(int, double, int, std::unordered_map<int, Node*>&, 
	   double, std::unordered_set<int>&);
	void updateOldRank();

friend class Graph;
};

#endif
