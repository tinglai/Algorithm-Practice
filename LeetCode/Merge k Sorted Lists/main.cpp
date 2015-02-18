#include <iostream>
#include <queue>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

struct Comp{
	bool operator()(const ListNode* n1, const ListNode* n2){
		return n1->val > n2->val;
	}
};

class Solution{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists){
		ListNode* result = NULL;
		if(lists.empty()) return result;
		priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
		for(unsigned int i = 0; i < lists.size(); i++){
			if(lists[i] != NULL) pq.push(lists[i]);
		}
		if(pq.empty()) return result;
		result = pq.top();
		ListNode* itr = result;
		pq.pop();
		if(result->next) pq.push(result->next);
		while(!pq.empty()){
			ListNode* temp = pq.top();
			itr->next = temp;
			itr = itr->next;
			pq.pop();
			temp = temp->next;
			if(temp) pq.push(temp);
		}
		return result;
    }
};

int main(){
	ListNode* n11 = new ListNode(2);
	ListNode* n12 = new ListNode(3);
	ListNode* n13 = new ListNode(7);
	ListNode* n14 = new ListNode(8);
	n11->next = n12;
	n12->next = n13;
	n13->next = n14;

	ListNode* n21 = new ListNode(1);
	ListNode* n22 = new ListNode(7);
	ListNode* n23 = new ListNode(12);
	ListNode* n24 = new ListNode(13);
	n21->next = n22;
	n22->next = n23;
	n23->next = n24;

	ListNode* n31 = new ListNode(4);
	ListNode* n32 = new ListNode(8);
	ListNode* n33 = new ListNode(11);
	ListNode* n34 = new ListNode(19);
	n31->next = n32;
	n32->next = n33;
	n33->next = n34;

	vector<ListNode*> lists = {NULL};
	//vector<ListNode*> lists = {};
	
	Solution soln;
	ListNode* result = soln.mergeKLists(lists);
	while(result){
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}
