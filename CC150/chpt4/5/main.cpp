#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
struct Node{
	T data;
	Node* left = NULL;
	Node* right = NULL;

	Node(){}
	Node(T in):data(in){}
};

template <typename T>
bool isBST(Node<T>*);

template <typename T>
bool isBST2(Node<T>*, int, int);

int main(){
	Node<int>* lll = new Node<int>(0);
	Node<int>* ll = new Node<int>(1);
	Node<int>* llr = new Node<int>(2);
	Node<int>* l = new Node<int>(3);
	Node<int>* lr = new Node<int>(4);
	Node<int>* lrr = new Node<int>(4);
	Node<int>* root = new Node<int>(6);
	Node<int>* rl = new Node<int>(7);
	Node<int>* rlr = new Node<int>(8);
	Node<int>* r = new Node<int>(9);
	Node<int>* rr = new Node<int>(10);
	Node<int>* rrr = new Node<int>(11);

	root->left = l;
	root->right = r;
	l->left = ll;
	l->right = lr;
	r->left = rl;
	r->right = rr;
	ll->left = lll;
	ll->right = llr;
	lr->right = lrr;
	rl->right = rlr;
	rr->right = rrr;

//version 1
	cout << "*** This is the result of version 1 ***" << endl;
	if(isBST(root))
		cout << "This binary tree is a BST" << endl;
	else
		cout << "This binary tree is not a BST" << endl;

cout << endl;
	cout << "*** This is the result of version 1 ***" << endl;
	if(isBST2(root, INT_MIN, INT_MAX))
		cout << "This binary tree is a BST" << endl;
	else
		cout << "This binary tree is not a BST" << endl;


}

template <typename T>
void flat(Node<T>* root, vector<T>& flattenTree){
	if(root == NULL) return;
	flat(root->left, flattenTree);
	flattenTree.push_back(root->data);
	flat(root->right, flattenTree);
}

template <typename T>
bool isBST(Node<T>* root){
//using the property that a BST is the smallest at the far left side
//and its data increases as it goes right
//this method needs O(N) in time since it needs to traverse the tree and
//visit all the nodes to compare their data
//this method needs O(N) in space since it needs to store data in Nodes.
//Actually it needs O(log(N)) for the recursion frame, while since O(log(N))
//is neglegible compared to O(N), it doesn't matter.
	vector<T> flattenTree;
	flat(root, flattenTree);
	if(flattenTree.size() == 1)
		return true;
	T temp = flattenTree[0];
	for(unsigned int i = 1; i < flattenTree.size(); i++){
		if(temp > flattenTree[i])
			return false;
		temp = flattenTree[i];
	}
	return true;
}

//Actually the above method has a drawback that is it cannot tell the case as following
//                   4
//  			    / \
//  			   2   5
//  			  / \
//  			 2   2        
//strictly, this is not a BST but this method cannot tell it
//the following method will make an improvement, both in terms of space as wellas solve this problem
//here we assume that when occur an tie, the later comming one should be on the left subtree of the node
//with the same value. i.e
//                   4
//  			    / \
//  			   2   5
//  			  / \
//  			 2   3    
//is legel while the other way is not.

template <typename T>
bool isBST2(Node<T>* root, int min, int max){
//this method use another way to solve thie problem. It sets a range of the value of each node
//and update the range and check if the following nodes' values are within the range.
//it will only need O(log(N)) in space since it only need space for the recursion
//the time complexity is O(N)
	if(root == NULL) return true;
	if(root->data <= min || root->data > max)
		return false;
	return(isBST2(root->left, min, root->data) &&
			  isBST2(root->right, root->data, max));
}
