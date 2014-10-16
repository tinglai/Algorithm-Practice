#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next = NULL;

	Node(){}
	Node(int in):data(in){}
};

Node* findLoop(Node*);
Node* initialize(int*, int);
void deconstruct(Node*, Node*);

int main(){
	Node* head = new Node(1);
	Node* node1 = head;
	Node* node2 = new Node(2);
	node1->next = node2;
	Node* node3 = new Node(3);
	node2->next = node3;
	Node* node4 = new Node(4);
	node3->next = node4;
	Node* node5 = new Node(5);
	node4->next = node5;
	Node* node6 = new Node(6);
	node5->next = node6;
	Node* node7 = new Node(7);
	node6->next = node7;
	Node* node8 = new Node(8);
	node7->next = node8;
	Node* node9 = new Node(9);
	node8->next = node9;
	Node* node10 = new Node(10);
	node9->next = node10;
	node10->next = node6;
	Node* loopHead = findLoop(head);
	cout << "the loop start at " << loopHead->data << endl;
	deconstruct(head, loopHead);
	deconstruct(loopHead->next, loopHead);
	delete loopHead;
}

Node* findLoop(Node* head){
	Node* fast = head;
	Node* slow = fast;
	do{
		fast = fast->next->next;
		slow = slow->next;
	}while(slow != fast);

	Node* loopHead = head;
	while(loopHead != slow){
		loopHead = loopHead->next;
		slow = slow->next;
	}
	
	return loopHead;
}

Node* initialize(int* array, int n){
	Node* head = new Node(array[0]);
	Node* temp = head;
	for(int i = 1; i < n; i++){
		Node* in = new Node(array[i]);
		temp->next = in;
		temp = in;
	}
	return head;
}

void deconstruct(Node* head, Node* loopHead){
	while(head != NULL && head != loopHead){
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}
