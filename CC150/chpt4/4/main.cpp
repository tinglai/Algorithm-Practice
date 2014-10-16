#include <iostream>
#include <queue>
#include <vector>
#include <list>

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
struct ListNode{
	T data;
	ListNode* next = NULL;

	ListNode(){}
	ListNode(T in):data(in){}
};

template <typename T>
void createList_version1(Node<T>*, vector<ListNode<T>*>&);
template <typename T>
void createList_recursion(Node<T>*, vector<list<T>*>&, int);
//The vector is used to store all the head of the linkedlists

int main(){
	Node<int>* root = new Node<int>(0);
	Node<int>* l1 = new Node<int>(1);
	Node<int>* l2 = new Node<int>(2);
	Node<int>* l22 = new Node<int>(22);
	Node<int>* l11 = new Node<int>(11);
	Node<int>* l12 = new Node<int>(12);
	Node<int>* l121 = new Node<int>(121);
	Node<int>* l122= new Node<int>(122);
	Node<int>* l1221= new Node<int>(1221);

	root->left = l1;
	root->right = l2;
	l1->left = l11;
	l1->right = l12;
	l12->left = l121;
	l12->right = l122;
	l2->right = l22;
	l122->left = l1221;

//the first version
	cout << "*** This is the first version output" << endl;
	vector<ListNode<int>*> lists1;
	createList_version1(root, lists1);
	cout << lists1.size() << endl << endl;
	for(unsigned int i = 0; i < lists1.size(); i++){
		ListNode<int>* j = lists1[i];
		while(j){
			cout << j->data << ' ';
			j = j->next;
		}
		cout << endl;
	}

cout << endl;
//the second version
	vector<list<int>*> lists2;
	cout << "*** This is the second version output" << endl;
	createList_recursion(root, lists2, 0);
	cout << lists2.size() << endl << endl;
	for(unsigned int i = 0; i < lists2.size(); i++){
		list<int>::iterator j = lists2[i]->begin();
		while(j != lists2[i]->end()){
			cout << *j << ' ';
			j++;
		}
		cout << endl;
	}
}

template <typename T>
void createList_recursion(Node<T>* root, vector<list<T>*>& listHead, int level){
	if(root == NULL){
		return;
	}
	if(level >= int(listHead.size())){
		list<T>* newList = new list<T>;
		listHead.push_back(newList);
	}
	listHead[level]->push_back(root->data);
	createList_recursion(root->left, listHead, level + 1);
	createList_recursion(root->right, listHead, level + 1);
}



template <typename T>
void createList_version1(Node<T>* root, vector<ListNode<T>*>& listHead){
//the complexity in time is O(N) where N is the number of all the nodes in the tree
//since the algorithm traverses all the nodes
//the complexity in space is O(N)
	queue<Node<T>*> q;
	q.push(root);
	while(!q.empty()){
//firstly push the first node to vector as head of the linked list
		int breadth = q.size();
		Node<T>* front = q.front();
		ListNode<T>* head = new ListNode<T>(front->data);
		listHead.push_back(head);
		if(front->left)
			q.push(front->left);
		if(front->right)
			q.push(front->right);
		q.pop();
		front = NULL;
//then add the rest of the nodes in the same depth into the linked list
		for(int i = 1; i < breadth; i++){
			Node<T>* temp = q.front();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			ListNode<T>* in = new ListNode<T>(temp->data);
			head->next = in;
			head = head->next;
			q.pop();
			temp = NULL;
		}
	}
}
