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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
		TreeNode* result = NULL;
		if(inorder.size() == 0 || postorder.size() == 0) return result;
		result = help(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
		return result;
    }
	TreeNode* help(vector<int>& inorder, vector<int>& postorder,
				int postorderHead, int inorderA, int inorderB){
		if(inorderA > inorderB) return NULL;
		TreeNode* root = new TreeNode(postorder[postorderHead]);
		if(inorderA == inorderB) return root;
		int i;
		for(i = inorderA; i < inorderB; i++){
			if(inorder[i] == postorder[postorderHead]) break;
		}
		root->right = 
				help(inorder, postorder, postorderHead - 1, i + 1, inorderB);
		root->left = 
				help(inorder, postorder, postorderHead - 1 - inorderB + i, inorderA, i - 1);
		return root;
	}
};

void inorderPrint(TreeNode* root){
	if(root == NULL) return;
	inorderPrint(root->left);
	cout << root->val << " ";
	inorderPrint(root->right);
}

void postorderPrint(TreeNode* root){
	if(root == NULL) return;
	postorderPrint(root->left);
	postorderPrint(root->right);
	cout << root->val << " ";
}

int main(){
	//vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
	vector<int> inorder = {2, 1};
	//vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
	vector<int> postorder = {1, 2};
	Solution soln;
	TreeNode* result = soln.buildTree(inorder, postorder);
	cout << "inorder:" << endl;
	inorderPrint(result);
	cout << endl;
	cout << "postorder:" << endl;
	postorderPrint(result);
	cout << endl;
}
