#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *partition(ListNode *head, int x){
		//if(head == NULL) return head;
		ListNode* first = NULL, *second = NULL;
		ListNode* itr = head;
		while(itr){
			if(itr->val < x){
				if(first == NULL) first = itr;
			}
			else{
				if(second == NULL) second = itr;
			}
			if(first && second){
				break;
			}
			itr = itr->next;
		}
		if(first == NULL || second == NULL) return head;
		itr = head;
		ListNode* itr1 = NULL;
		ListNode* itr2 = NULL;
		while(itr){
			if(itr->val >= x){
				if(itr2 == NULL) itr2 = itr;
				else{
					itr2->next = itr;
					itr2 = itr2->next;
				}
			}
			else{
				if(itr1 == NULL) itr1 = itr;
				else{
					itr1->next = itr;
					itr1 = itr1->next;
				}
			}
			itr = itr->next;
		}
		itr2->next = NULL;
		itr1->next = second;
		return first;
    }
};

int main(){
	ListNode* n1 = new ListNode(6);
	ListNode* n2 = new ListNode(5);
	ListNode* n3 = new ListNode(4);
	ListNode* n4 = new ListNode(3);
	ListNode* n5 = new ListNode(2);
	ListNode* n6 = new ListNode(1);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	Solution soln;
	ListNode* result = soln.partition(n1, 3);
	while(result){
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}
