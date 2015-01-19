#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
		if(preorder.empty()) return NULL;
		if(preorder.size() != inorder.size()) return NULL;
		if(preorder.size() == 1){
			TreeNode* root = new TreeNode(preorder[0]);
			return root;
		}
		
		TreeNode* root;
		int size = (int)inorder.size();
		root = help(preorder, inorder, 0, 0, size - 1);
		return root;
    }

	TreeNode* help(vector<int>& preorder, vector<int> &inorder,
					  int prea, int ina, int inb){
	//ina and inb are head idx and end idx of inorder vector correspondingly
	//prea is head idx of preorder vector	

		TreeNode* root = new TreeNode(preorder[prea]);
		if(inb == ina) return root;

		int i = ina;
		for(; i < inb; i++){
			if(inorder[i] == preorder[prea]) break;
		}

		if(i == ina){
			root->left = NULL;
		}
		else{
			root->left = help(preorder, inorder, prea + 1, ina, i - 1);
		}
		if(i == inb){
			root->right = NULL;
		}
		else{
			root->right = help(preorder, inorder, prea + i - ina + 1, i + 1, inb);
		}
		return root;
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
	vector<int> preorder = {-1};
	vector<int> inorder = {-1};

	Solution soln;
	TreeNode* root;
	root = soln.buildTree(preorder, inorder);

	cout << "preorder:" << endl;
	preorderPrint(root);
	cout << endl;
	cout << "inorder:" << endl;
	inorderPrint(root);
	cout << endl;
}
