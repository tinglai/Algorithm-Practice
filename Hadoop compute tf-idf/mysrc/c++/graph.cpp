#include "graph.h"
#include "node.h"
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

//***member functions of Graph class***
Graph::Graph(int argc, char** argv){
	if(argc != 6){
		cout << "error in number of arguements" << endl;
	}

	d = atof(argv[1]);//the first argv is the number of the exe file
	mode = argv[2];
	if(mode == "-k"){
		iteration = atoi(argv[3]);
	}
	else if(mode == "-converge"){
		accuracy = atof(argv[3]);
	}
	else{ 
		cout << "error: mode is either -k or -converge" << endl;
		exit(1);
	}
	const char* inFile = argv[4];
	const char* outFile = argv[5];
	ifstream inStream(inFile);
	outStream.open(outFile);
	string read;
	inStream >> read;//<eecs485_edges>
int t1, t2;
while(true){
inStream >> read;//<eecs485_edge>
if(read[14] == 's') break;

inStream >> read;//from node
//t1 = read.find('>');
t1 = 13;
t2 = read.find('<', t1 + 1);
string temp = read.substr(t1 + 1, t2 - t1 - 1);
int from_id = stoi(temp);
if(allNodes.count(from_id) == 0){
Node* in = new Node(1);
addNode(from_id, in);
}

inStream >> read;//to node
//t1 = read.find('>');
t1 = 11;
t2 = read.find('<', t1 + 1);
temp = read.substr(t1 + 1, t2 - t1 - 1);
int to_id = stoi(temp);
if(allNodes.count(to_id) == 0){
Node* in = new Node(1);
addNode(to_id, in);
}

inStream >> read;//</eecs485_edge>
}

N = allNodes.size();

unordered_map<int, Node*>::iterator itr = allNodes.begin();
while(itr != allNodes.end()){
(itr->second)->rank = (itr->second)->rank / N;
(itr->second)->oldRank = (itr->second)->oldRank / N;
itr++;
}

inStream.close();
inStream.open(inFile);
inStream >> read;//<eecs485_edges>

while(true){
inStream >> read;//<eecs485_edge>
if(read[14] == 's') break;

inStream >> read;//from node
//t1 = read.find('>');
t1 = 13;
t2 = read.find('<', t1 + 1);
string temp = read.substr(t1 + 1, t2 - t1 - 1);
int from = stoi(temp);

inStream >> read;//to node
//t1 = read.find('>');
t1 = 11;
t2 = read.find('<', t1 + 1);
temp = read.substr(t1 + 1, t2 - t1 - 1);
int to = stoi(temp);

if(from != to){
allNodes[from]->addOutput();
allNodes[to]->addIncome(from);
}

inStream >> read;//</eecs485_edge>
}

for(itr = allNodes.begin(); itr != allNodes.end(); itr++){
if(itr->second->getOutputSize() == 0){
//add edges to sink nodes
sinkNodes.emplace(itr->first);
}
}

/*
while(inStream){
inStream >> read;
int from = stoi(read);
inStream >> read;
int to = stoi(read);
if(from != to){
//scan out the self cycle
//allNodes[from]->addOutput(to);
allNodes[from]->addOutput();
allNodes[to]->addIncome(from);
}
}
unordered_map<int, Node*>::iterator i;

for(i = allNodes.begin(); i != allNodes.end(); i++){
if(i->second->getOutputSize() == 0){
//add edges to sink nodes
sinkNodes.emplace(i->first);
}
}
*/
}//Graph::Graph...

void Graph::addNode(int id, Node* node){
allNodes.emplace(id, node);
}

void Graph::Kpagerank(){
unordered_map<int, Node*>::iterator i;
for(int count = 0; count < iteration; count++){
double sinkRank = 0;
unordered_set<int>::iterator j;
for(j = sinkNodes.begin(); j != sinkNodes.end(); j++){
sinkRank += allNodes[*j]->getOldRank() / (N - 1);
}

for(i = allNodes.begin(); i != allNodes.end(); i++){
i->second->updateRank(i->first, d, N, allNodes, sinkRank, sinkNodes);
}
for(i = allNodes.begin(); i != allNodes.end(); i++){
i->second->updateOldRank();
}
}
for(i = allNodes.begin(); i != allNodes.end(); i++){
outStream << i->first << ',' << i->second->getRank() << endl;
}
outStream.close();
}

void Graph::Cpagerank(){
unordered_map<int, Node*>::iterator i;
bool ifStop;
while(true){
ifStop = true;
double sinkRank = 0;
unordered_set<int>::iterator j;
for(j = sinkNodes.begin(); j != sinkNodes.end(); j++){
sinkRank += allNodes[*j]->getOldRank() / (N - 1);
}
for(i = allNodes.begin(); i != allNodes.end(); i++){
i->second->updateRank(i->first, d, N, allNodes, sinkRank, sinkNodes);
}
for(i = allNodes.begin(); i != allNodes.end(); i++){
double difference = fabs(i->second->getRank()
- i->second->getOldRank())
/i->second->getOldRank();
if(difference > accuracy){
ifStop = false;
break;
}
}
if(ifStop){
break;
}
for(i = allNodes.begin(); i != allNodes.end(); i++){
i->second->updateOldRank();
}
}
for(i = allNodes.begin(); i != allNodes.end(); i++){
outStream << i->first << ',' << i->second->getRank() << endl;
}
outStream.close();
}

Graph::~Graph(){
unordered_map<int, Node*>::iterator i;
for(i = allNodes.begin(); i != allNodes.end(); i++){
delete i->second;
}

