#include <iostream>

using namespace std;

template<typename T>
struct TreeNode{
	T data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;

	TreeNode(){}
	TreeNode(T in):data(in){}
};

template<typename T>
int isBalanced(TreeNode<T>*);
//if the tree is not balanced
//return -1

int main(){
	TreeNode<int>* root = new TreeNode<int>(0);
	TreeNode<int>* node11 = new TreeNode<int>(1);//the first node on the first layer below root
	TreeNode<int>* node12 = new TreeNode<int>(2);//the second node on the first layer below root
	TreeNode<int>* node21 = new TreeNode<int>(3);//the first node on the second layer below root
	TreeNode<int>* node22 = new TreeNode<int>(4);//the second node on the second layer below root
	TreeNode<int>* node23 = new TreeNode<int>(5);//the third node on the second layer below root
	TreeNode<int>* node24 = new TreeNode<int>(6);//the forth node on the second layer below root
	root->left = node11;
	//root->right = node12;
	node11->left = node21;
	node11->right = node22;
	//node12->left = node23;
	//node12->right = node24;
/*
	for(int i = 1; i < 10; i++){
		TreeNode<int>* left = new TreeNode<int>(i);
		TreeNode<int>* right = new TreeNode<int>(i);
		temp->left = left;
		temp->right = right;
		temp = temp->left;
	}
*/
	if(isBalanced(root) == -1){
		cout << "the tree is not balanced" << endl;
	}
	else{
		cout << "the tree is balanced" << endl;
	}
}

template<typename T>
int isBalanced(TreeNode<T>* root){
//I start from the leaf points and return the height up to the root
//and the hight of non-leaf node is calculated based on its left and 
//right children's heights. in this case there is no need to recalculate 
//height of each node again. 
//the time complexity = O(N), where N is the number of the nodes in a tree
//the space complexity = O(H), where H is the height of the tree
//thus the space is in O(log(N)) 
	if(root == NULL) return 0;
	else{
		int leftHight = isBalanced(root->left);
		int rightHight = isBalanced(root->right);
		if(leftHight - rightHight > 1 ||
		   rightHight - leftHight > 1){
			return -1;
		}
		else{
			return leftHight > rightHight ? leftHight + 1:
											rightHight + 1;
		}
	}
}
