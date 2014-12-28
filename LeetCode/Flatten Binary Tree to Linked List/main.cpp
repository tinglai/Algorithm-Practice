#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
//this is not in-place
public:
    void flatten(TreeNode *root) {
		vector<TreeNode*> temp;
		help(root, temp);
		TreeNode* rt = root;
		for(unsigned int i = 1; i < temp.size(); i++){
			rt->left = NULL;
			rt->right = temp[i];
			rt = temp[i];
		}
    }
	void help(TreeNode *root, vector<TreeNode*>& temp){
		if(root == NULL) return;
		temp.push_back(root);
		help(root->left, temp);
		help(root->right, temp);
	}
};

class Solution{
// here is a tricky algorithm
// we transform the binary tree as following
//       1               1                    1
//      / \               \                    \
//     2   3     ->        2          ->        2
//    / \   \             / \                    \
//   4   5   6           4   5                    4
//                            \                    \
//                             3                    5
//                              \                    \
//                               6                    3
//                                                     \
//                                                      6
//basically, we let the right most point of the left subtree
//connect to the right subtree
public:
    void flatten(TreeNode *root) {
		TreeNode *rightMost;
		while(root){
			if(root->left){
				rightMost = root->left;
				while(rightMost->right){
					rightMost = rightMost->right;
				}
				rightMost->right = root->right;
				root->right = root->left;
				root->left = NULL;
				root = root->right;
			}
			else{
				root = root->right;
			}
		}
    }
};


int main(){
	TreeNode* a1 = new TreeNode(1);
	TreeNode* a21 = new TreeNode(2);
	//TreeNode* a22 = new TreeNode(5);
	TreeNode* a31 = new TreeNode(3);
	//TreeNode* a32 = new TreeNode(4);
	//TreeNode* a34 = new TreeNode(6);

	a1->left = a21;
	//a1->right = a22;
	a21->left = a31;
	//a21->right = a32;
	//a22->right = a34;

/*
	Solution1 soln1;
	soln1.flatten(a1);
*/
	Solution soln;
	soln.flatten(a1);

	TreeNode* itr = a1;
	while(itr != NULL){
		cout << itr->val << ' ';
		itr = itr->right;
	}
	cout << endl;
}
