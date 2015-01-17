#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		
		ListNode* itr1 = l1;
		ListNode* itr2 = l2;
		ListNode* result;
		ListNode* end;
		if(itr1->val < itr2->val){
			result = itr1;
			end = itr1;
			itr1 = itr1->next;
		}
		else{
			result = itr2;
			end = itr2;
			itr2 = itr2->next;
		}

		while((itr1 != NULL) & (itr2 != NULL)){
			if(itr1->val < itr2->val){
				end->next = itr1;
				end = end->next;
				itr1 = itr1->next;
			}
			else{
				end->next = itr2;
				end = end->next;
				itr2 = itr2->next;
			}
		}

		if(itr1 != NULL){
			end->next = itr1;
			end = end->next;
		}
		if(itr2 != NULL){
			end->next = itr2;
			end = end->next;
		}
		return result;
    }
};

int main(){
	ListNode* l11 = new ListNode(11);
	ListNode* l12 = new ListNode(23);
	ListNode* l13 = new ListNode(24);
	ListNode* l14 = new ListNode(35);
	ListNode* l15 = new ListNode(56);
	l11->next = l12;
	l12->next = l13;
	l13->next = l14;
	l14->next = l15;

	ListNode* l21 = new ListNode(1);
	ListNode* l22 = new ListNode(13);
	ListNode* l23 = new ListNode(34);
	ListNode* l24 = new ListNode(35);
	ListNode* l25 = new ListNode(36);
	l21->next = l22;
	l22->next = l23;
	l23->next = l24;
	l24->next = l25;

	Solution soln;
	ListNode* result = soln.mergeTwoLists(l11, l21);
	while(result != NULL){
		cout << result->val << endl;
		result = result->next;
	}
}
