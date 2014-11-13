#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
		if(head == NULL) return;
		if(head->next == NULL) return;
		ListNode *fast = head;
		ListNode *slow = head;
		while(fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		if(fast != NULL){
		//when the number of nodes in the list is odd
			slow = slow->next;
		}
		//now slow is the head of the later half sublist
		ListNode *a, *b, *c;
		a = slow;
		b = slow->next;
		while(b != NULL){
			c = b->next;
			b->next = a;
			a = b;
			b = c;
		}
		//above loop reverse the order of the later half sublist
		ListNode *first = head;//first iterates the first half sublist
		ListNode *second = a;//second iterates the second half sublist
		ListNode *temp1;
		ListNode *temp2;
		while(second != slow){
			temp1 = first->next;
			temp2 = second->next;
			first->next = second;
			second->next = temp1;
			first = temp1;
			second = temp2;
		}
		temp1 = first->next;
		first->next = second;
		if(second == temp1){
			second->next = NULL;
		}
		else{
			second->next = temp1;
			temp1->next = NULL;
		}
    }
};

int main(){
	ListNode *a = new ListNode(0);
/*
	ListNode *b = new ListNode(1);
	ListNode *c = new ListNode(2);
	ListNode *d = new ListNode(3);
	ListNode *e = new ListNode(4);
	ListNode *f = new ListNode(5);
	ListNode *g = new ListNode(6);
	ListNode *h = new ListNode(7);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
*/
	Solution solt;
	solt.reorderList(a);
	ListNode* i = a;
	while(i != NULL){
		cout << i->val << ' ';
		i = i->next;
	}
	cout << endl;
}
