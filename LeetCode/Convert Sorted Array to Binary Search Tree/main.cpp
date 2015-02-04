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
    TreeNode *sortedArrayToBST(vector<int> &num){
		TreeNode* root = help(num, 0, (int)num.size() - 1);
		return root;
    }
	TreeNode* help(vector<int>& num, int a, int b){
		if(b < a) return NULL;
		
		int mid = (a + b) / 2;
		TreeNode* root = new TreeNode(num[mid]);
		TreeNode* left = help(num, a, mid - 1);
		TreeNode* right = help(num, mid + 1, b);
		root->left = left;
		root->right = right;
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
	//vector<int> num = {1, 2, 3, 4, 5, 6, 7};
	vector<int> num = {};
	Solution soln;
	TreeNode *result = soln.sortedArrayToBST(num);
	//TreeNode *result = soln.sortedListToBST(test);
	
	inorderPrint(result);
	cout << endl;
	preorderPrint(result);
	cout << endl;
}
