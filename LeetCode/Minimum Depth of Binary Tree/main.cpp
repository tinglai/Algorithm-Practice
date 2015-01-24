#include <iostream>
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
    int minDepth(TreeNode *root){
		if(root == NULL) return 0;
		int result = 1;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()){
			int size = que.size();
			for(int i = 0; i < size; i++){
				TreeNode *tempNode = que.front();
				if((tempNode->left == NULL) && (tempNode->right == NULL)){
					return result;
				}
				if(tempNode->left) que.push(tempNode->left);
				if(tempNode->right) que.push(tempNode->right);
				que.pop();
			}
			result++;
		}
		return result;
    }
};

int main(){
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);

	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;
	n4->left = n6;

	Solution soln;
	int result = soln.minDepth(n1);
	cout << "result = " << result << endl;
}
