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
    vector<vector<int> > levelOrderBottom(TreeNode *root){
		vector<vector<int>> result;
		if(root == NULL) return result;
		queue<TreeNode*> q;
		q.push(root);
		vector<vector<int>> buffer;
		while(!q.empty()){
			int size = (int)q.size();
			vector<int> toPush;
			for(int i = 0; i < size; i++){
				toPush.push_back(q.front()->val);
				if(q.front()->left) q.push(q.front()->left);
				if(q.front()->right) q.push(q.front()->right);
				q.pop();
			}
			buffer.push_back(toPush);
		}
		for(int i = (int)buffer.size() - 1; i >= 0; i--){
			result.push_back(buffer[i]);
		}
		return result;
    }
};

int main(){
	TreeNode* n1 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(9);
	TreeNode* n3 = new TreeNode(20);
	TreeNode* n4 = new TreeNode(15);
	TreeNode* n5 = new TreeNode(7);

	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;

	Solution soln;
	vector<vector<int>> result = soln.levelOrderBottom(n1);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}
