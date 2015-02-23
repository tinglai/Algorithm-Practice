#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution{
public:
    void recoverTree(TreeNode *root) {
		TreeNode* a = NULL;
		TreeNode* b = NULL;
		TreeNode* prev = NULL;
		int count = 0;
		help(prev, a, b, count, root);
		swap(a->val, b->val);
    }
	void help(TreeNode*& prev, TreeNode*& a, TreeNode*& b, int& count, TreeNode* root){
		if(b != NULL && count == 2)return;
		if(root == NULL) return;

		help(prev, a, b, count, root->left);

		if(prev != NULL){
			if(prev->val > root->val){
				if(count == 0) a = prev;
				b = root;
				count ++;
			}
		}
		prev = root;

		help(prev, a, b, count, root->right);
	}
};

void inorderPrint(TreeNode* n1){
	if(n1 == NULL) return;
	inorderPrint(n1->left);
	cout << n1->val << ' ';
	inorderPrint(n1->right);
}

int main(){
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);

	n2->left = n3;
	n2->right = n1;
	inorderPrint(n2);
	cout << endl;

	Solution soln;
	soln.recoverTree(n2);
	inorderPrint(n2);
	cout << endl;
}
