#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next = NULL;

	Node(int in):data(in){}
	Node(){}
};

Node* add(Node*, Node*, int);
Node* initialize(int*, int);
void print(Node*);
void deconstruct(Node*);

int main(){
	int array1[] = {1,2,3,4,5,6,7};
	int array2[] = {3,5,8,4,5,7,2};
	Node* head1 = initialize(array1, 7);
	Node* head2 = initialize(array2, 7);
	cout << "first list is" << endl;
	print(head1);
	cout << "second list is" << endl;
	print(head2);
	Node* result = add(head1, head2, 0);
	cout << "the result is " << endl;
	print(result);
	deconstruct(head1);
	deconstruct(head2);
	deconstruct(result);
}

Node* add(Node* lt1, Node* lt2, int carry){
	if(lt1 == NULL && lt2 == NULL){
		if(carry == 0){
			return NULL;
		}
		else{
			Node* temp = new Node(carry);
			return temp;
		}
	}
	else{
		int sum;
		sum = (lt1 == NULL ? 0: lt1->data) +
			  (lt2 == NULL ? 0: lt2->data) +
			  carry;
		Node* result = new Node(sum % 10);
		result->next = add(lt1 == NULL ? NULL: lt1->next,
						   lt2 == NULL ? NULL: lt2->next,
						   sum >= 10 ? 1: 0);
		return result;
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
