#include <iostream>

using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution{
public:
    void connect(TreeLinkNode *root){
		//the trick here is to use what you have done into your later
		//process
		if(!root) return;
		if(!root->left) return;
		//root->left->next = root->right;
		TreeLinkNode* first = root;
		TreeLinkNode* itr = first;
		TreeLinkNode* memo;
		while(first->left){
			itr = first;
			while(itr){
				itr->left->next = itr->right;
				memo = itr->right;
				itr = itr->next;
				if(itr) memo->next = itr->left;
				else break;
			}
			first = first->left;
		}
    }
};

int main(){
	TreeLinkNode *n1 = new TreeLinkNode(1);
	TreeLinkNode *n2 = new TreeLinkNode(2);
	TreeLinkNode *n3 = new TreeLinkNode(3);
	TreeLinkNode *n4 = new TreeLinkNode(4);
	TreeLinkNode *n5 = new TreeLinkNode(5);
	TreeLinkNode *n6 = new TreeLinkNode(6);
	TreeLinkNode *n7 = new TreeLinkNode(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	Solution soln;
	soln.connect(n1);
	TreeLinkNode* itr1 = n1;
	TreeLinkNode* itr2 = n1;
	while(itr1->left){
		itr2 = itr1->left;
		while(itr2){
			cout << itr2->val << endl;
			itr2 = itr2->next;
		}
		itr1 = itr1->left;
	}
	
}
