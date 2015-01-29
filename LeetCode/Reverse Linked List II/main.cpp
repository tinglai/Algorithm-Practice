#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n){
		if(m == n) return head;
		ListNode* itr = head;
		ListNode* start;
		
		for(int i = 1; i < m; i++){
			itr = itr->next;
		}
		if(m != 1){
			start = head;
			for(int i = 1; i < m - 1; i++){
				start = start->next;
			}
		}
		
		ListNode* memo = itr;
		ListNode* a = itr;
		ListNode* b = itr->next;
		for(int i = 0; i < n - m; i++){
			ListNode* temp = b->next;
			b->next = a;
			a = b;
			b = temp;
		}
		memo->next = b;
		if(m == 1) head = a;
		else start->next = a;
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

	int m, n;
	cout << "m = "; cin >> m;
	cout << "n = "; cin >> n;
	Solution soln;
	ListNode* result = soln.reverseBetween(n1, m, n);
	while(result){
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}
