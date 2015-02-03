#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
		ListNode* itrA = headA, itrB = headB;
		int lengthA = 0, lengthB = 0;
		while(itrA){
			lengthA++;
			itrA = itrA->next;
		}
		while(itrB){
			lengthB++;
			itrB = itrB->next;
		}
		if(lengthA == 0 || lengthB == 0) return NULL;
		itrA = headA;
	}
	void reverse(ListNode* head){
		
	}
};
