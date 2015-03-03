#include "node.h"
#include <unordered_map>
#include <unordered_set>
#include "graph.h"

using namespace std;

//***member functions of Node class***
void Node::addIncome(int id){
	income.push_back(id);
}

/*
void Node::addOutput(int id){
	//output.push_back(id);
}
*/
void Node::addOutput(){
	outPutSize++;
}

int Node::getOutputSize(){
	return outPutSize;
	//return output.size();
}

double Node::getRank(){
	return rank;
}

double Node::getOldRank(){
	return oldRank;
}

void Node::updateRank(int id, double d, int N, unordered_map<int, Node*>& allNodes, 
   double sinkRank, unordered_set<int>& sinkNodes){
	double tempSum = 0;
	for(unsigned int i = 0; i < income.size(); i++){
		int outSize = allNodes[income[i]]->getOutputSize();
		tempSum += (allNodes[income[i]]->getOldRank() / (double)outSize);
	}
	if(sinkNodes.count(id) == 0){
		tempSum += sinkRank;
		//if not sink node
	}
	else{
		//if is sink node, need to exclude the selfcycle
		tempSum = tempSum + sinkRank - oldRank / (N - 1);
	}
	rank = ((1 - d) / (double)N) + d * tempSum;
}

void Node::updateOldRank(){
	oldRank = rank;
}
