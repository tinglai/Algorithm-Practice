#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *insertionSortList(ListNode *head){
		if(head == NULL) return head;
		ListNode* sortedEnd = head;//point to the last node in sorted list
		ListNode* i = head->next;
		sortedEnd->next = NULL;
		ListNode* j;
		while(i != NULL){
			ListNode* unsortedBegin = i->next;
			//point to the first node in the unsorted list
			i->next = NULL;
			j = head;
			while(j != NULL){
				if(i->val < j->val){
					int temp = j->val;
					i->next = j->next;
					j->next = i;
					j->val = i->val;
					i->val = temp;
					if(j == sortedEnd){
						sortedEnd = i;
					}
					break;
				}
				j = j->next;
			}
			if(j == NULL){
				sortedEnd->next = i;
				sortedEnd = i;
			}
			i = unsortedBegin;
		}
		return head;
    }
};

int main(){
	ListNode* n1 = new ListNode(5);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(1);
	ListNode* n6 = new ListNode(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	Solution soln;
	ListNode* head = soln.insertionSortList(n1);
	//ListNode* head = soln.insertionSortList(NULL);
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
