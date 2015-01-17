#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root){
		vector<int> result;
		help(root, result);
		return result;
    }
	void help(TreeNode* root, vector<int>& result){
		if(root == NULL){
			return;
		}
		help(root->left, result);
		help(root->right, result);
		result.push_back(root->val);
	}
};

int main(){
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n21 = new TreeNode(2);
	TreeNode* n22 = new TreeNode(3);
	TreeNode* n31 = new TreeNode(4);
	TreeNode* n32 = new TreeNode(5);
	TreeNode* n33 = new TreeNode(6);
	TreeNode* n34 = new TreeNode(7);
	
	n1->left = n21;
	n1->right = n22;
	n21->left = n31;
	n21->right = n32;
	n22->left = n33;
	n22->right = n34;

	Solution soln;
	vector<int> result = soln.postorderTraversal(n1);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
}
