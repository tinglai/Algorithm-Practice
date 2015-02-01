#include <iostream>
#include <vector> 

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum){
		vector<vector<int>> result;
		if(root == NULL) return result;
		vector<int> memo;
		help(root, sum, result, memo);
		return result;
    }
	void help(TreeNode* root, int sum, vector<vector<int>>& result, vector<int>& memo){
		if(root == NULL) return;
		if(root->left == NULL && root->right == NULL){
			if(sum == root->val){
				vector<int> toPush = memo;
				toPush.push_back(root->val);
				result.push_back(toPush);
			}
			else return;
		}
		int target = sum - root->val;
		memo.push_back(root->val);
		if(root->left){
			help(root->left, target, result, memo);
		}
		if(root->right){
			help(root->right, target, result, memo);
		}
		memo.pop_back();
	}
};

int main(){
	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(4);
	TreeNode* n3 = new TreeNode(8);
	TreeNode* n4 = new TreeNode(11);
	TreeNode* n5 = new TreeNode(13);
	TreeNode* n6 = new TreeNode(4);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(2);
	TreeNode* n9 = new TreeNode(5);
	TreeNode* n10 = new TreeNode(1);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	n4->left = n7;
	n4->right = n8;
	n6->left = n9;
	n6->right = n10;

	int sum = 22;
	Solution soln;
	vector<vector<int>> result = soln.pathSum(n1, sum);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
