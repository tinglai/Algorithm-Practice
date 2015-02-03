#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *sortList(ListNode *head){
		int size = 0;
		ListNode* itr = head;
		while(itr){
			size++;
			itr = itr->next;
		}
		if(size <= 1) return head;
		head = help(head);
		return head;
    }

	ListNode* help(ListNode* head){
		if(head == NULL) return NULL;
		int size = 0;
		ListNode* itr = head;
		while(itr){
			size++;
			itr = itr->next;
		}
		if(size <= 1) return head;

		ListNode* second = divide(head);
		head = help(head);
		second = help(second);
		head = merge(head, second);
		return head;
	}

	ListNode* divide(ListNode* head){
		if(head == NULL) return NULL;
		if(head->next == NULL) return head;
		ListNode* fast = head->next;
		ListNode* slow = head;
		while(fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* toReturn = slow->next;
		slow->next = NULL;
		return toReturn;
	}

	ListNode* merge(ListNode* head1, ListNode* head2){
		if(head2 == NULL) return head1;
		ListNode* head;
		ListNode *itr1, *itr2;
		if(head1->val < head2->val){
			head = head1;
			itr1 = head1->next;
			itr2 = head2;
		}
		else{
			head = head2;
			itr1 = head1;
			itr2 = head2->next;
		}
		ListNode* itr = head;
		while(itr1 && itr2){
			if(itr1->val < itr2->val){
				itr->next = itr1;
				itr = itr->next;
				itr1 = itr1->next;
			}
			else{
				itr->next = itr2;
				itr = itr->next;
				itr2 = itr2->next;
			}
		}
		while(itr1){
			itr->next = itr1;
			itr = itr->next;
			itr1 = itr1->next;
		}
		while(itr2){
			itr->next = itr2;
			itr = itr->next;
			itr2 = itr2->next;
		}
		return head;
	}
};

int main(){
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(5);
	ListNode* n4 = new ListNode(7);
	ListNode* n5 = new ListNode(3);
	ListNode* n6 = new ListNode(1);
	ListNode* n7 = new ListNode(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	Solution soln;
	ListNode* head = soln.sortList(n1);
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
