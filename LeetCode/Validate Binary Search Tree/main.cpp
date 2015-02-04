#include <iostream>
#include <climits>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	bool ifMax = false, ifMin = false;
    bool isValidBST(TreeNode *root){
		if(root == NULL) return true;
		return help(root, INT_MAX, INT_MIN);
    }
	bool help(TreeNode* root, int upperBd, int lowerBd){
//the main weakness of this method is that it assumes that
//input will not be INT_MAX or INT_MIN, which however in practice,
//is true. In that case we need to be very careful to deal
//with the corner case when the input has INT_MIN or INT_MAX
		if(root == NULL) return true;
		if(root->val < lowerBd || root->val > upperBd){
			return false;
		}
		if(root->val == lowerBd || root->val == upperBd){
			if(root->val == INT_MAX){
				if(ifMax) return false;
				else ifMax = true;
			}
			else if(root->val == INT_MIN){
				if(ifMin) return false;
				else ifMin = true;
			}
			else return false;
		}
		bool left = help(root->left, root->val, lowerBd);
		bool right = help(root->right, upperBd, root->val);
		return (left && right);
		
	}
};

int main(){
	TreeNode* n1 = new TreeNode(2147483647);
	TreeNode* n2 = new TreeNode(3);
	TreeNode* n3 = new TreeNode(-2147483648);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);

	n1->right = n3;
/*
	n1->left = n2;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
*/

	Solution soln;
	bool result = soln.isValidBST(n1);
	if(result) cout << "yes, it is valid" << endl;
	else cout << "no, it is not valid" << endl;
}
