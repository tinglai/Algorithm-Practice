#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next = NULL;

	Node(int in): data(in){}
	Node(){}
};

Node* add(Node*, Node*, int&);
int length(Node*);
void makeup(Node*&, Node*&);//make to lists the same length
						  //by adding nodes with data = 0
						  //in front of the shorter list
Node* initialize(int*, int);
void print(Node*);
void deconstruct(Node*);

int main(){
	int array1[] = {1,2,3,4,8,6};
	int array2[] = {1,2,8};
	Node* head1 = initialize(array1, 6);
	Node* head2 = initialize(array2, 3);
	cout << "head1 = " << endl;
	print(head1);
	cout << "head2 = " << endl;
	print(head2);
	makeup(head1, head2);
	cout << "after makeup, head1 = " << endl;
	print(head1);
	cout << "after makeup, head2 = " << endl;
	print(head2);
	int carry = 0;
	Node* result = add(head1, head2, carry);
	cout << "the result = " << endl;
	print(result);
	deconstruct(head1);
	deconstruct(head2);
	deconstruct(result);
}

Node* add(Node* lt1, Node* lt2, int& carry){
	if(lt1 == NULL && lt2 == NULL){
		return NULL;
	}
	Node* result = new Node;
	result->next = add(lt1->next, lt2->next, carry);
	int sum = lt1->data + lt2->data + carry;
	result->data = sum % 10;
	if(sum >= 10) carry = 1;
	else carry = 0;
	return result;
}

int length(Node* head){
	int size = 0;
	while(head != NULL){
		size++;
		head = head -> next;
	}
	return size;
}

void makeup(Node*& lt1, Node*& lt2){
	int length1 = length(lt1);
	int length2 = length(lt2);
	if(length1 > length2){
		for(int i = 0; i < length1 - length2; i++){
			Node* in = new Node(0);
			in->next = lt2;
			lt2 = in;
		}
	}
	else{
		for(int i = 0; i < length2 - length1; i++){
			Node* in = new Node(0);
			in->next = lt1;
			lt1 = in;
		}
	}
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

void print(Node* head){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next;
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
