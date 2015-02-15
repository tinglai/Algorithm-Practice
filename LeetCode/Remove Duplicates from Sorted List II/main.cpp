#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *deleteDuplicates(ListNode *head){
		if(head == NULL) return NULL;
		if(head->next == NULL) return head;
		ListNode *itr1 = head, *itr2 = head->next;
		while(itr2){
			if(itr2->val != itr1->val){
				itr1 = itr1->next;
				itr2 = itr2->next;
			}
			else{
				while(itr2 && itr2->val == itr1->val){
					itr2 = itr2->next;	
				}
				if(itr2 == NULL){
					if(itr1 == head) return NULL;
					ListNode* itr = head;
					while(itr->next != itr1){
						itr = itr->next;
					}
					itr->next = NULL;
					return head;
				}
				else{
					itr1->next = itr2->next;
					itr1->val = itr2->val;
					itr2 = itr1->next;
				}
			}
		}
		return head;
    }
};

int main(){
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(2);
	ListNode* n5 = new ListNode(2);
	ListNode* n6 = new ListNode(2);
	ListNode* n7 = new ListNode(8);
	ListNode* n8 = new ListNode(8);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;

	Solution soln;
	ListNode* result = soln.deleteDuplicates(n1);
	while(result){
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}
