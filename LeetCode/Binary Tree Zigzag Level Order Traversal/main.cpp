#include <iostream>
#include <deque>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		if(root == NULL) return result;
		std::deque<TreeNode*> deq;
		deq.push_back(root);
		int depth = 0;
		TreeNode* temp = NULL;
		while(!deq.empty()){
			if(depth % 2 == 0){
				int count = deq.size();
				vector<int> in;
				for(int i = 0; i < count; i++){
					temp = deq.front();
					in.push_back(temp->val);
					if(temp->left != NULL){
						deq.push_back(temp->left);
					}
					if(temp->right != NULL){
						deq.push_back(temp->right);
					}
					deq.pop_front();
				}
				result.push_back(in);
			}
			else{
				int count = deq.size();
				vector<int> in;
				for(int i = 0; i < count; i++){
					temp = deq.back();
					in.push_back(temp->val);
					if(temp->right != NULL){
						deq.push_front(temp->right);
					}
					if(temp->left != NULL){
						deq.push_front(temp->left);
					}
					deq.pop_back();
				}
				result.push_back(in);
			}
			depth++;
		}
	return result;
    }
};

void print(std::vector<std::vector<int>> result){
	int outSize = result.size();
	for(int i = 0; i < outSize; i++){
		int inSize = result[i].size();
		for(int j = 0; j < inSize; j++){
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	TreeNode *a = new TreeNode(0);
	TreeNode *b = new TreeNode(1);
	TreeNode *c = new TreeNode(2);
	TreeNode *d = new TreeNode(3);
	TreeNode *e = new TreeNode(4);
	TreeNode *f = new TreeNode(5);
	TreeNode *g = new TreeNode(6);
	TreeNode *h = new TreeNode(7);
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->right = f;
	e->left = g;
	e->right = h;
	Solution solt;
	cout << "the zigzag traversal of this tree is as following" << endl;
	print(solt.zigzagLevelOrder(a));
}
