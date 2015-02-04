#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode *sortedListToBST(ListNode *head){
		TreeNode *root = help(head);
		return root;
    }
	TreeNode* help(ListNode* head){
		if(head == NULL) return NULL;
		ListNode* firstHead;
		ListNode* secondHead;
		ListNode* mid = devide(head, firstHead, secondHead);
		TreeNode* root = new TreeNode(mid->val);
		TreeNode* left = help(firstHead);
		TreeNode* right = help(secondHead);
//actually if we use inorder recursion instead of preorder by 
//keeying record of length of sublist, we
//can skip the devide step and make the algorithm complexity into O(n)
		root->left = left;
		root->right = right;
		return root;
	}
	ListNode* devide(ListNode *head, ListNode*& firstHead, ListNode*& secondHead){
		if(head == NULL){
			firstHead = NULL;
			secondHead = NULL;
			return NULL;
		}
		if(head->next == NULL){
			firstHead = NULL;
			secondHead = NULL;
			return head;
		}
		ListNode* fast = head->next;
		ListNode* slow = head;
		while(fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		secondHead = slow->next;
		slow->next = NULL;
		if(slow == head){
			firstHead = NULL;
		}
		else{
			firstHead = head;
			for(fast = head; fast->next != slow; fast = fast->next){}
			fast->next = NULL;
		}
		return slow;
	}
};

void inorderPrint(TreeNode* root){
	if(root == NULL) return;
	inorderPrint(root->left);
	cout << root->val << " ";
	inorderPrint(root->right);
}

void preorderPrint(TreeNode* root){
	if(root == NULL) return;
	cout << root->val << " ";
	preorderPrint(root->left);
	preorderPrint(root->right);
}

int main(){
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	//ListNode* test = NULL;
	Solution soln;
	TreeNode *result = soln.sortedListToBST(n1);
	//TreeNode *result = soln.sortedListToBST(test);
	
	inorderPrint(result);
	cout << endl;
	preorderPrint(result);
	cout << endl;
}
