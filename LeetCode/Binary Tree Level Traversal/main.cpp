#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
		vector<vector<int>> result;
		if(root == NULL) return result;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()){
			vector<int> toPush;
			int size = (int)que.size();
			for(int i = 0; i < size; i++){
				TreeNode* temp = que.front();
				toPush.push_back(temp->val);
				if(temp->left) que.push(temp->left);
				if(temp->right) que.push(temp->right);
				que.pop();
			}
			result.push_back(toPush);
		}
		return result;
    }
};

int main(){
	TreeNode* n11 = new TreeNode(3);
	TreeNode* n21 = new TreeNode(9);
	TreeNode* n22 = new TreeNode(20);
	TreeNode* n33 = new TreeNode(15);
	TreeNode* n34 = new TreeNode(7);

	n11->left = n21;
	n11->right = n22;
	n22->left = n33;
	n22->right = n34;

	vector<vector<int>> result;
	Solution soln;
	result = soln.levelOrder(n11);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
