#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "graph.h"
#include "node.h"

using namespace std;

int main(int argc, char** argv){
	Graph graph(argc, argv);
	string mode = argv[2];
	if(mode == "-k"){
		graph.Kpagerank();
	}
	else if(mode == "-converge"){
		graph.Cpagerank();
	}
	else{
		cout << "you have error in mode selection" << endl;
	}
}

