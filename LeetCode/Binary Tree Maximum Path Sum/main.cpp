#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    int maxPathSum(TreeNode *root){
		int result = INT_MIN;
		help(root, result);
		return result;
    }
	int help(TreeNode *root, int &result){
//help function return maximum path with the toppest node to be node root
		if(root == NULL) return 0;
		int left = help(root->left, result);
		int right = help(root->right, result);

		int path = root->val;
		if(left > 0) path += left;
		if(right > 0) path += right;

		if(path > result) result = path;

		int toReturn = root->val;
		if(left > right){
			if(left > 0) toReturn += left;
		}
		else{
			if(right > 0) toReturn += right;
		}
		
		return toReturn;
	}
};

int main(){
	TreeNode* n11 = new TreeNode(9);
	TreeNode* n21 = new TreeNode(6);
	TreeNode* n22 = new TreeNode(-3);
	TreeNode* n31 = new TreeNode(-6);
	TreeNode* n32 = new TreeNode(2);
	TreeNode* n41 = new TreeNode(2);
	TreeNode* n51 = new TreeNode(-6);
	TreeNode* n52 = new TreeNode(-6);
	TreeNode* n61 = new TreeNode(-6);

	n11->left = n21;
	n11->right = n22;
	n22->left = n31;
	n22->right = n32;
	n32->left = n41;
	n41->left = n51;
	n41->right = n52;
	n51->left = n61;

	Solution soln;
	int result = soln.maxPathSum(n11);
	cout << "result = " << result << endl;
}
