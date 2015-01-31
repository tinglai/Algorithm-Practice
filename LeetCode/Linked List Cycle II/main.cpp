#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
		if(head == NULL) return NULL;
		ListNode* fast = head;
		ListNode* slow = head;

		while(1){
			if(fast->next == NULL || fast->next->next == NULL){
				return NULL;
			}
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow) break;
		}

		ListNode* chase = head;
		while(chase != slow){
			slow = slow->next;
			chase = chase->next;
		}
		return chase;
    }
};

int main(){
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);
	ListNode* n8 = new ListNode(8);
	ListNode* n9 = new ListNode(9);
	ListNode* n10 = new ListNode(10);

	n1->next = n1;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;

	Solution soln;
	ListNode* result = soln.detectCycle(n1);
	if(result == NULL){
		cout << "There is no cycle in this list" << endl;
	}
	else{
		cout << "The entrance of the cycle of the list is " << result->val << endl;
	}
}
