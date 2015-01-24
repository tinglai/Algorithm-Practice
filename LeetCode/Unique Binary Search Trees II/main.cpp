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
    vector<TreeNode *> generateTrees(int n){
		vector<TreeNode*> result;
		if(n <= 0){
			result.push_back(NULL);
			return result;
		}
		help(n, result, n);
		return result;
    }
	void help(int n, vector<TreeNode*>& trees, int top){
	//generate BST's s.t the size of the tree is n
	//with largest number among the tree to be top
	//store the root of those trees in vector trees
		if(n == 0){
			return;
		}
		else{
			for(int i = top - n + 1; i <= top; i++){
				//i denotes the val of root of the tree
				vector<TreeNode*> leftSubtree;
				vector<TreeNode*> rightSubtree;
				help(i - top + n - 1, leftSubtree, i - 1);
				help(top - i, rightSubtree, top);
				if(leftSubtree.empty() && rightSubtree.empty()){
					TreeNode* root = new TreeNode(i);
					trees.push_back(root);
				}
				if(leftSubtree.empty()){
					for(unsigned p = 0; p < rightSubtree.size(); p++){
						TreeNode* root = new TreeNode(i);
						root->right = rightSubtree[p];
						trees.push_back(root);
					}
				}
				else if(rightSubtree.empty()){
					for(unsigned p = 0; p < leftSubtree.size(); p++){
						TreeNode* root = new TreeNode(i);
						root->left = leftSubtree[p];
						trees.push_back(root);
					}
				}
				else{
					for(unsigned j = 0; j < leftSubtree.size(); j++){
						for(unsigned p = 0; p < rightSubtree.size(); p++){
							TreeNode* root = new TreeNode(i);
							root->left = leftSubtree[j];
							root->right = rightSubtree[p];
							trees.push_back(root);
						}
					}
				}
			}
		}
	}
};

void byLevelPrint(TreeNode* root){
	if(root == NULL) return;
	queue<TreeNode*> que;
	que.push(root);
	while(!que.empty()){
		int size = (int)que.size();
		for(int i = 0; i < size; i++){
			TreeNode* temp = que.front();
			cout << temp->val << " ";
			if(temp->left) que.push(temp->left);
			if(temp->right) que.push(temp->right);
			que.pop();
		}
		cout << endl;
	}
}

int main(){
	int n;
	cout << "n = "; cin >> n;
	Solution soln;
	vector<TreeNode*> result = soln.generateTrees(n);
cout << "result.size() = " << result.size() << endl;
	for(unsigned int i = 0; i < result.size(); i++){
		TreeNode* temp = result[i];
		cout << "********" << endl;
		byLevelPrint(temp);
		cout << endl;
	}
}
