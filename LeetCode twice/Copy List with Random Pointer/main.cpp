#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL){}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head){
		if(!head) return NULL;
		RandomListNode *itr = head;
		unordered_map<RandomListNode*, int> memo1;
		for(int i = 0; itr != NULL; itr = itr->next, i++){
			memo1.emplace(itr, i);
		}
		vector<RandomListNode*> memo2;
		for(itr = head; itr != NULL; itr = itr->next){
			RandomListNode* in = new RandomListNode(itr->label);
			memo2.push_back(in);
		}
		for(int i = 0; i < memo2.size() - 1; i++){
			memo2[i]->next = memo2[i + 1];
		}
		itr = head;
		for(int i = 0; itr != NULL; itr = itr->next, i++){
			if(itr->random) memo2[i]->random = memo2[memo1[itr->random]];
		}
		return memo2[0];
	}
};

int main(){
	RandomListNode* n1 = new RandomListNode(1);
	RandomListNode* n2 = new RandomListNode(2);
	RandomListNode* n3 = new RandomListNode(3);
	RandomListNode* n4 = new RandomListNode(4);
	RandomListNode* n5 = new RandomListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	n1->random = n1;
	n2->random = n4;
	n3->random = n1;
	n4->random = n5;

	if(n5->random) cout << "bababab" << endl;

	Solution soln;
	RandomListNode* result = soln.copyRandomList(n1);
	RandomListNode* itr = result;
	while(itr != NULL){
		cout << "label = " << itr->label;
		if(itr->next) cout << " next = " << itr->next->label;
		else cout << " no next";
		if(itr->random) cout << " random = " << itr->random->label << endl;
		else cout << " no random" << endl;
		cout << "hehe" << endl;
		itr = itr->next;
	}
}
