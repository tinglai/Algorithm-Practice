#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    bool isSymmetric(TreeNode *root){
		if(root == NULL) return true;
		return help(root->left, root->right);
    }
	bool help(TreeNode* n1, TreeNode* n2){
		if(n1 == NULL && n2 == NULL) return true;
		else if(n1 == NULL || n2 == NULL) return false;
		else if(n1->val != n2->val) return false;
		bool res1 = help(n1->left, n2->right);
		bool res2 = help(n1->right, n2->left);
		return res1 && res2;
	}
};

int main(){
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(2);
	TreeNode* n4 = new TreeNode(3);
	TreeNode* n5 = new TreeNode(4);
	TreeNode* n6 = new TreeNode(4);
	TreeNode* n7 = new TreeNode(3);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	Solution soln;
	bool result = soln.isSymmetric(n1);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
