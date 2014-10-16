#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node* next;
	
	Node(T in): data(in){}
};

template <typename T>
void partition(Node<T>*&, T);
template <typename T>
Node<T>* initialize(T*, int);
template <typename T>
void print(Node<T>*);
template <typename T>
void deconstruct(Node<T>*);


int main(){
	int array1[] = {10,9,8,7,6,5,4,3,2,1};
	Node<int>* head1 = initialize(array1, 10);
	cout << "before partition, the list is as following:" << endl;
	print(head1);
	cout << "x = " << endl;
	int x;
	cin >> x;
	partition(head1, x);
	cout << "after partition, the list is as following:" << endl;
	print(head1);
	deconstruct(head1);
}

template <typename T>
void partition(Node<T>* &head, T x){
//here I firstly find the first node whose value is >= x, denote as big
//if big is the last node of the list or no nodes have value >= x, then
//I am done
//Otherwise, I use another pointer bigend to traverse the list after the
//pointer big. If bigend->data >= x, leave it there and move forward.
//otherwise put the node bigend pointing to in front of head.
	Node<T>* big = head;
	while(big->data < x && big->next != NULL){
		big = big->next;
	}//allocate the first node whose value >= x

	//if the first node whose value >= x appears 
	//before the last node, we need furthur actions
	if(big->next != NULL){
		Node<T>* bigend = big;//bigend points to the
				      //last node whose value > x
		while(bigend->next != NULL){
			if(bigend->next->data >= x){
				bigend = bigend->next;
			}
			else{
				Node<T>* temp = bigend->next;
				bigend->next = temp->next;
				temp->next = head;
				head = temp;
			}
		}
	}
}

template <typename T>
Node<T>* initialize(T* array, int n){
	if(n <= 0) return NULL;
	Node<T>* head = new Node<T>(array[0]);
	Node<T>* temp = head;
	for(int i = 1; i < n; i++){
		Node<T>* in = new Node<T>(array[i]);
		temp->next = in;
		temp = in;
	}
	return head;
}

template <typename T>
void print(Node<T>* head){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}
template <typename T>
void deconstruct(Node<T>* head){
	while(head != NULL){
		Node<T>* temp = head->next;
		delete head;
		head = temp;
	}
}
