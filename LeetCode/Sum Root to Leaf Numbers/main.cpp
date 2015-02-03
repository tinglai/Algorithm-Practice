#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int sumNumbers(TreeNode *root){
		int result = 0;
		help(root, 0, result);
		return result;
    }
	void help(TreeNode* root, int cur, int& result){
		if(root == NULL) return;
		cur = cur * 10 + root->val;
		if(root->left == NULL && root->right == NULL){
			result += cur;
		}
		else{
			help(root->left, cur, result);
			help(root->right, cur, result);
		}
	}
};

int main(){
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	Solution soln;
	int sum = soln.sumNumbers(n1);
	cout << "sum = " << sum << endl;
}
