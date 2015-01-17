#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n){
		if(n <= 0) return NULL;
		ListNode *early = head;

		ListNode *late = head;
		for(int i = 0; i < n; i++){
			if(early == NULL) return NULL;
			early = early->next;
		}

		if(early == NULL){
			ListNode* temp = head;
			head = head->next;
			delete temp;
		}
		else{
			while(early->next != NULL){
				early = early->next;
				late = late->next;
			}
			ListNode* temp = late->next;
			late->next = temp->next;
			delete temp;
		}
		return head;
    }
};

int main(){
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);

/*
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
*/

	int n;
	cout << "n = ";
	cin >> n;
	
	Solution soln;
	ListNode* result = soln.removeNthFromEnd(n1, n);
	while(result){
		cout << result->val << " "; 
		result = result->next;
	}
	cout << endl;
}
