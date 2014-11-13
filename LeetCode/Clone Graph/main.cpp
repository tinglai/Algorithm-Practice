#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL) return NULL;
		unordered_map<int, UndirectedGraphNode*> newNodes;
		unordered_set<int> inQue;
		vector<UndirectedGraphNode*> oldNodes;

		queue<UndirectedGraphNode*> que;//this is a queue of nodes to be created
		que.push(node);
		inQue.emplace(node->label);
		UndirectedGraphNode *temp;

		while(!que.empty()){
			temp = que.front();
			UndirectedGraphNode *in = 
			   new UndirectedGraphNode(temp->label);
			newNodes.emplace(temp->label, in);
			for(unsigned int i = 0; i < (temp->neighbors).size(); i++){
				if(inQue.count((temp->neighbors)[i]->label) == 0){
					que.push((temp->neighbors)[i]);
					inQue.emplace((temp->neighbors)[i]->label);
				}
			}
			que.pop();
			oldNodes.push_back(temp);
		}
		//by now the nodes of graph have been copied. following code will implement
		//the copy of edges
		for(unsigned int i = 0; i < oldNodes.size(); i++){
			UndirectedGraphNode *curr = oldNodes[i];
			for(unsigned int j = 0; j < (curr->neighbors).size(); j++){
				((newNodes[curr->label])->neighbors).push_back(newNodes[(curr->neighbors)[j]->label]);
			}
		}
		UndirectedGraphNode *toReturn = newNodes[(node->label)];
		return toReturn;
    }
};

int main(){
	UndirectedGraphNode *a = new UndirectedGraphNode(0);
	UndirectedGraphNode *b = new UndirectedGraphNode(1);
	UndirectedGraphNode *c = new UndirectedGraphNode(2);
	UndirectedGraphNode *d = new UndirectedGraphNode(3);
	UndirectedGraphNode *e = new UndirectedGraphNode(4);
	UndirectedGraphNode *f = new UndirectedGraphNode(5);
	a->neighbors = {b, f};
	b->neighbors = {c, f};
	c->neighbors = {d};
	d->neighbors = {e, e};
	e->neighbors = {f, f};

	Solution slot;
	UndirectedGraphNode *result = slot.cloneGraph(a);
}
