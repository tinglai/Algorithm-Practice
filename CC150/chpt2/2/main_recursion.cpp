#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int dt): data(dt), next(NULL){}
};

int kthToLast(Node*, int);
Node* initialise(int*, int);
void print(Node*);
int tale(Node*, Node*);
void deconstruct(Node*);

int main(){
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	Node* head = initialise(array, 10);
	cout << "the list is as following:" << endl;
	print(head);
	cout << "k = " << endl;
	int k;
	cin >> k;
	cout << "the kth to last element is : " << kthToLast(head, k) << endl;
	deconstruct(head);
}

int kthToLast(Node *head, int k){
//here using a tale recursion, but the basic idea is the same as 
//the non-recursive version
	if(head == NULL){
		cout << "the list is empty" << endl;
		return 0;
	}
	Node *temp = head;
	for(int i = 0; i < k; i++){
		temp = temp->next;
		if(temp == NULL && i < k - 1){
			cout << "k is greater than the size of the list" << endl;
			return 0;
		}
	}
	return tale(head, temp);
}

int tale(Node* current, Node* runner){
	if(runner == NULL){
		return current->data;
	}
	else{
		return tale(current->next, runner->next);
	}
}

Node* initialise(int array[], int n){
	if(n == 0) return NULL;
	else{
		Node* head = new Node(array[0]);
		Node* temp = head;
		//temp is used to point the last node in the list
		for(int i = 1; i < n; i++){
			Node* in = new Node(array[i]);
			temp->next = in;
			temp = in;
		}
		return head;
	}
}

void print(Node* head){
	Node* i = head;
	while(i != NULL){
		cout << i->data << ' ';
		i = i->next;
	}
	cout << endl;
}

void deconstruct(Node* head){
	while(head != NULL){
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}
