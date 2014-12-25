#include <iostream>
#include <>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	struct MyNode{
		int maxSum;
		int l;
		int r;
		TreeNode node;
	}
public:
    int maxPathSum(TreeNode *root) {
    }

	int halfSum(TreeNode *root){
		if(node == NULL){
			return 0;
		}
		else{
			int l = halfSum(node->left);
			int r = halfSum(node->right);
			if(l > r){
				return node->val + l;
			}
			else{
				return node->val + r;
			}
		}
	}
};
