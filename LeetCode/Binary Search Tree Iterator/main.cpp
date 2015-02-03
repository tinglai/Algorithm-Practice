#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class BSTIterator{
public:
	queue<int> memo;

    BSTIterator(TreeNode *root){
		help(root, memo);
    }
	void help(TreeNode *root, queue<int>& memo){
		if(root == NULL) return;
		help(root->left, memo);
		memo.push(root->val);
		help(root->right, memo);
	}
    /** @return whether we have a next smallest number */
    bool hasNext(){
		return(!memo.empty());
    }
    /** @return the next smallest number */
    int next(){
		int toReturn = (memo.front());
		memo.pop();
		return toReturn;
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
	TreeNode* n1 = new TreeNode(4);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(6);
	TreeNode* n4 = new TreeNode(1);
	TreeNode* n5 = new TreeNode(3);
	TreeNode* n6 = new TreeNode(5);
	TreeNode* n7 = new TreeNode(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	BSTIterator i = BSTIterator(n1);
	while(i.hasNext()) cout << i.next() << endl;
}
