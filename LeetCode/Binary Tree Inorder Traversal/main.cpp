#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
//this is implemented in iterative way
//in which firstly push left children to a stack until
//reaching the leftmost node
//then determine if that node
//has right child. if there is a right child, push the 
//child into the stack, else go to the parent node of
//the current node until there is a right child or the 
//stack is empty
		vector<int> result;
		if(root == NULL) return result;
		stack<TreeNode*> container;
		container.push(root);
		TreeNode* curr;
		while(!container.empty()){
			curr = container.top();
			if(curr->left != NULL){
				container.push(curr->left);
			}
			else{
				result.push_back(curr->val);
				container.pop();
				if(curr->right != NULL){
					container.push(curr->right);
				}
				else{
					while(curr->right == NULL && !container.empty()){
						curr = container.top();
						result.push_back(curr->val);
						container.pop();
					}
					if(curr->right != NULL){
						container.push(curr->right);
					}
				}
			}
		}
		return result;
    }
};

int main(){
	TreeNode *a = new TreeNode(0);
	TreeNode *b = new TreeNode(1);
	TreeNode *c = new TreeNode(2);
	TreeNode *d = new TreeNode(3);
	TreeNode *e = new TreeNode(4);
	TreeNode *f = new TreeNode(5);
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	Solution solt;
	vector<int> result = solt.inorderTraversal(a);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << ' ';
	}
	cout << endl;
}
