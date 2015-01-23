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
		ListNode *fast = head->next;
		//this is a good trick to find the mid node of the list
		//note that the fast pointer starts from head->next;
		//then when the loop is over, slow is always at the mid
		//of the list
		ListNode *slow = head;
		while(fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *a = slow->next;
		ListNode *b = a->next;
		slow->next = NULL;//cut the list from mid
		a->next = NULL;

		while(b!= NULL){
			ListNode *temp = b->next;
			b->next = a;
			a = b;
			b = temp;
		}
		//at the end of this loop, a is the head of the second half list
		//after reversion

		while(a != NULL){
		//the second half list is always shorter than the first half
			ListNode *temp = a->next;
			a->next = head->next;
			head->next = a;
			head = a->next;
			a = temp;
		}

/*
		temp1 = first->next;
		first->next = second;
		if(second == temp1){
			second->next = NULL;
		}
		else{
			second->next = temp1;
			temp1->next = NULL;
		}
*/
    }
};

int main(){
	ListNode *a = new ListNode(0);
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

	Solution solt;
	solt.reorderList(a);
	ListNode* i = a;
	while(i != NULL){
		cout << i->val << ' ';
		i = i->next;
	}
	cout << endl;
}
