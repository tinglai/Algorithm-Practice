#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL) return head;
		ListNode* i = head->next;//i is used as an iterator
		ListNode* last = head;
		//last is used to store the node with last non-replicated value
		while(i != NULL){
			if(i->val == last->val){
				last->next = i->next;
				//actually here an delete of the duplicated node is needed
			}
			else{
				last = i;
			}
			i = last->next;
		}
		return head;
    }
};

void print(ListNode* root){
	while(root != NULL){
		cout << root->val << ' ';
		root = root->next;
	}
	cout << endl;
}

int main(){
	ListNode* a = new ListNode(1); 
	ListNode* b = new ListNode(1); 
	ListNode* c = new ListNode(3); 
	ListNode* d = new ListNode(3); 
	ListNode* e = new ListNode(3); 
	ListNode* f = new ListNode(6); 
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	cout << "The original list is" << endl;
	print(a);
	cout << "The list after deleting duplicated nodes" << endl;
	Solution solt;
	print(solt.deleteDuplicates(a));
}
