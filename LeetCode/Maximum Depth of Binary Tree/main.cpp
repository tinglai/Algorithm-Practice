#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    int maxDepth(TreeNode *root){
		if(root == NULL) return 0;
		int leftMaxDepth = maxDepth(root->left);
		int rightMaxDepth = maxDepth(root->right);
		if(leftMaxDepth > rightMaxDepth) return leftMaxDepth + 1;
		else return rightMaxDepth + 1;
    }
};

int main(){
	TreeNode* n11 = new TreeNode(1);
	TreeNode* n21 = new TreeNode(2);
	TreeNode* n22 = new TreeNode(3);
	TreeNode* n31 = new TreeNode(4);
	TreeNode* n41 = new TreeNode(5);

	n11->left = n21;
	n11->right = n22;
	n21->left = n31;
	n31->left = n41;

	Solution soln;
	int result = soln.maxDepth(n11);
	cout << "result = " << result << endl;
}
