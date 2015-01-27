#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *swapPairs(ListNode *head){
		if(head == NULL || head->next == NULL) return head;
		ListNode *a, *b;
		a = head;
		b = head->next;
		head = b;
		while(b){
			ListNode *c = b->next;
			ListNode *d;

			b->next = a;
			if(c == NULL){
				a->next = NULL;
				break;
			}
			else{
			 	d = c->next;
				if(d){
					a->next = d;
					a = c;
					b = d;
				}
				else{
					a->next = c;
					break;
				}
			}
		}
		return head;
    }
};

int main(){
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	Solution soln;
	//ListNode* result = new ListNode;
	ListNode* result = soln.swapPairs(n1);
	while(result){
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}
