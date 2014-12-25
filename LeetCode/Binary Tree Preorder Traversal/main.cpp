#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		help(root, result);
		return result;
    }
	void help(TreeNode *root, vector<int>& result){
		if(root == NULL){
			return;
		}
		else{
			result.push_back(root->val);
			help(root->left, result);
			help(root->right, result);
		}
	}
};

int main(){
	TreeNode *root = new TreeNode(0);
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *b1 = new TreeNode(3);
	TreeNode *b2 = new TreeNode(4);
	TreeNode *b3 = new TreeNode(5);
	TreeNode *b4 = new TreeNode(6);
	
	root->left = a1;
	root->right = a2;
	a1->left = b1;
	a1->right = b2;
	a2->left = b3;
	a2->right = b4;

	Solution sol;
	vector<int> result = sol.preorderTraversal(root);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << ' ';
	}
	cout << endl;
}
