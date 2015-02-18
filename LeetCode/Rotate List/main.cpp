#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *rotateRight(ListNode *head, int k){
		if(head == NULL) return head;
		int size = 0;
		ListNode* itr1 = head;
		while(itr1){
			size++;
			itr1 = itr1->next;
		}
		int time = k % size;
		if(time == 0) return head;
		ListNode* itr2 = head;
		for(int i = 0; i < time; i++){
			itr2 = itr2->next;
		}
		itr1 = head;
		while(itr2->next){
			itr1 = itr1->next;
			itr2 = itr2->next;
		}
		ListNode* temp = head;
		head = itr1->next;
		itr1->next = NULL;
		itr2->next = temp;

		return head;
    }
};

int main(){
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	int k;
	cout << "k = "; cin >> k;
	Solution soln;
	ListNode* result = soln.rotateRight(n1, k);
	while(result){
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}
