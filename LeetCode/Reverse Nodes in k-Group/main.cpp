#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//the time complexity is O(N) where N is the number of list nodes
//the space complexity is O(N) since we only need 6 pointers,
//specificly a, b, c, toReturn, head and end
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *a = head;
		if(!check(a, k)){
			return head;
		}
		ListNode *b = head->next;
		ListNode *c;
		for(int i = 0; i < k - 1; i++){
			c = b->next;
			b->next = a;
			a = b;
			b = c;
		}
		ListNode *toReturn = a;//this is the head of list after modification
		ListNode *end = head;//this is the end of the sublist that is newly modified
		head = b;
		a = head;
		while(check(a, k)){
			b = a->next;
			for(int i = 0; i < k - 1; i++){
				c = b->next;
				b->next = a;
				a = b;
				b = c;
			}
			end->next = a;
			end = head;
			head = b;
			a = head;
		}
			end->next = head;
		return toReturn;
    }

	bool check(ListNode *a, int k){
		for(int i = 0; i < k; i++){
			if(a == NULL){
				return false;
			}
			a = a->next;
		}
		return true;
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
	ListNode* b = new ListNode(2); 
	ListNode* c = new ListNode(3); 
	ListNode* d = new ListNode(4); 
	ListNode* e = new ListNode(5); 
	ListNode* f = new ListNode(6); 
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	cout << "The original list is" << endl;
	print(a);
	int k;
	cout << "k = ";
	cin >> k;
	cout << "The list after reverse k nodes" << endl;
	Solution solt;
	print(solt.reverseKGroup(a, k));
}
