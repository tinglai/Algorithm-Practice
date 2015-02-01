#include <iostream>
#include <unordered_map>
#include <cmath>
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
    bool isBalanced(TreeNode *root){
		if(root == NULL) return true;
		unordered_map<TreeNode*, int> memo;
		vector<TreeNode*> stk;
		stk.push_back(root);
		while(!stk.empty()){
			TreeNode* itr = stk.back();
			stk.pop_back();
			int left = help(itr->left, memo);
			int right = help(itr->right, memo);
			if(abs(left - right) > 1) return false;
			if(itr->left) stk.push_back(itr->left);
			if(itr->right) stk.push_back(itr->right);
		}
		return true;
    }
	int help(TreeNode *root, unordered_map<TreeNode*, int>& memo){
		if(root == NULL) return 0;
		if(memo.count(root) != 0) return memo[root];
		
		int left = 1 + help(root->left, memo);
		int right = 1 + help(root->right, memo);
		memo[root] = left > right? left: right;
		return memo[root];
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

	n1->right = n3;
	n3->left = n6;
	n3->right = n7;
	
	Solution soln;
	bool result = soln.isBalanced(n1);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
