#include <iostream>

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
Node<T>* buildBST(T*, int, int);

int main(){
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	Node<int>* root = buildBST(array, 0, 9);
	cout << root->data << ' ' << root->left->data << ' ' << root->right->data << endl;
	//cout << root->data << endl;
}

template <typename T>
Node<T>* buildBST(T* array, int start, int end){
	if(start > end){
		return NULL;
	}
	T in = array[(start + end) / 2];
	Node<T>* root = new Node<T>(in);
	root->left = buildBST(array, start, (start + end) / 2 - 1);
	root->right = buildBST(array, (start + end) / 2 + 1, end);
	return root;
}
