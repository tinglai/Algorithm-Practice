#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isPath_DFS(vector<vector<int>>&, int, int, vector<bool>&);
bool isPath_BFS(vector<vector<int>>&, int, int, vector<bool>&);

int main(){
	vector<vector<int> > graph(6);
	//here using a double vector to define a graph.
	//the inner vector records the ajacent nodes 
	//that each node is connected
	//e.g the inner vector graph[0] contains 1 and 2,
	//meaning node 0 is connected to 1 and 2;
	graph[0].push_back(1);
	graph[0].push_back(2);
	graph[1].push_back(0);
	graph[1].push_back(3);
	graph[2].push_back(3);
	graph[3].push_back(4);
	graph[4].push_back(2);
	graph[4].push_back(3);
	//graph[4].push_back(5);
	graph[4].push_back(0);
	graph[4].push_back(2);
	vector<bool> isVisited(graph.size(), false);
	int start = 0;
	int end = 5;
	//if(isPath_DFS(graph, start, end, isVisited)){
	if(isPath_BFS(graph, start, end, isVisited)){
		cout << "there is a path between " << start << " and " << end << endl;
	}
	else{
		cout << "there is no path between " << start << " and " << end << endl;
	}
}

bool isPath_DFS(vector<vector<int>>& graph, int start, int end, vector<bool>& isVisited){
	//this is a deep first search of a graph using recursion (acturally using the 
	//stack frame), in this case, the time complexity is O(N) and the space complexity
	//is O(K) where K is the depth of the graph, should be near O(log(N))
	if(start == end){
		return true;
	}
	if(!isVisited[start]){
		isVisited[start] = true;
		for(unsigned int i = 0; i < graph[start].size(); i++){
			if(isPath_DFS(graph, graph[start][i], end, isVisited)){
				return true;
			}
		}
	}
	return false;
}

bool isPath_BFS(vector<vector<int>>& graph, int start, int end, vector<bool>& isVisited){
	//this method is a breadth first search of a graph, using a queue for help.
	//the time complexity is O(N), it is a good way to look for a shortest path
	//between start and end
	if(start == end){
		return true;
	}
	queue<int> toSearch;
	toSearch.push(start);
	isVisited[start] = true;
	//once one node has been added to the queue, denote it as visited although it has not
	//been "literally" visited, so that one node will not be added twice into the queue
	while(!toSearch.empty()){
		int temp = toSearch.front();
		if(temp == end){
			return true;
		}
		for(unsigned int i = 0; i < graph[temp].size(); i++){
			if(!isVisited[graph[temp][i]]){
				toSearch.push(graph[temp][i]);
				isVisited[graph[temp][i]] = true;
			}
		}
		toSearch.pop();
	}
	return false;
}
