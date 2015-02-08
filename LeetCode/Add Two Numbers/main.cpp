#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		ListNode* itr1 = l1, *itr2 = l2;
		while(itr1 && itr2){
			itr1->val = itr1->val + itr2->val;
			itr2->val = itr1->val;
			itr1 = itr1->next;
			itr2 = itr2->next;
		}
		if(itr1 != NULL){
			itr1 = l1;
			int add = 0;
			ListNode* end;
			while(itr1){
				int digit = add + itr1->val;
				if(digit > 9){
					itr1->val = digit % 10;
					add = 1;
				}
				else{
					itr1->val = digit;
					add = 0;
				}
				end = itr1;
				itr1 = itr1->next;
			}
			if(add == 1) end->next = new ListNode(1);
			return l1;
		}
		else{
			itr2 = l2;
			int add = 0;
			ListNode* end;
			while(itr2){
				int digit = add + itr2->val;
				if(digit > 9){
					itr2->val = digit % 10;
					add = 1;
				}
				else{
					itr2->val = digit;
					add = 0;
				}
				end = itr2;
				itr2 = itr2->next;
			}
			if(add == 1) end->next = new ListNode(1);
			return l2;
		}
    }
};

int main(){
	ListNode* n11 = new ListNode(5);
	ListNode* n12 = new ListNode(4);
	ListNode* n13 = new ListNode(3);

	ListNode* n21 = new ListNode(5);
	ListNode* n22 = new ListNode(6);
	ListNode* n23 = new ListNode(4);

	n11->next = n12;
	n12->next = n13;
	n21->next = n22;
	n22->next = n23;

	Solution soln;
	ListNode* result = soln.addTwoNumbers(n11, n21);
	while(result){
		cout << result->val;
		result = result->next;
	}
	cout << endl;
}
