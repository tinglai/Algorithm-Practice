#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

// main idea is to firstly get length of A, and B, then reverse listA
// if there is intersection, iterate from headB, we will end at headA
// (if not, there is no intersection)
// then we can have a new length between headA and headB
// and we can calculate the length of the intersection part
// which equals to (lengthA + lengthB - lengthB2A + 1) / 2
// and with which we can easily find the intersection start
//
// actually a faster way is first get sum of listA
// then add 1 on each node of listB
// then calculate the sum of listA again
// if there is intersection, there should be difference
// between two sums and it shall not be hard to find out where
// the intersection is
class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
		ListNode* itrA = headA, *itrB = headB;
		int l1 = 0, l2 = 0, l3 = 0;
		while(itrA){
			l1++;
			itrA = itrA->next;
		}
		while(itrB){
			l2++;
			itrB = itrB->next;
		}
		if(l1 == 0 || l2 == 0) return NULL;
		itrA = reverse(headA);
		itrB = headB;
		while(itrB->next){
			l3++;
			itrB = itrB->next;
		}
		l3++;
		headA = reverse(itrA);
		if(itrB != headA) return NULL;
		int location =  l1 - ((l1 + l2 - l3 + 1) / 2) ;
		itrA = headA;
		for(int i = 0; i < location; i++){
			itrA = itrA->next;
		}
		return itrA;
	}
	ListNode* reverse(ListNode* head){
		if(head == NULL) return NULL;
		ListNode* itr1 = head;
		ListNode* itr2 = head->next;
		while(itr2){
			ListNode* temp = itr2->next;
			itr2->next = itr1;
			itr1 = itr2;
			itr2 = temp;
		}
		head->next = NULL;
		return itr1;
	}
};

int main(){
	ListNode* a1 = new ListNode(11);
	ListNode* a2 = new ListNode(12);
	ListNode* b1 = new ListNode(21);
	ListNode* b2 = new ListNode(22);
	ListNode* b3 = new ListNode(23);
	ListNode* c1 = new ListNode(31);
	ListNode* c2 = new ListNode(32);
	ListNode* c3 = new ListNode(33);

	a1->next = a2;
	b1->next = b2;
	b2->next = b3;
	c1->next = c2;
	c2->next = c3;

	a2->next = c1;
	b3->next = a1;
	
	Solution soln;
	ListNode* result = soln.getIntersectionNode(a1, b1);
	if(result) cout << "Result = " << result->val << endl;
	else cout << "No intersection" << endl;
}
