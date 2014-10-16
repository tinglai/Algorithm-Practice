#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node *next = NULL;

	Node(T dt):data(dt){}
};

template <typename T>
class myList{
public:
	Node<T> *head;//the first node
	Node<T> *end;//the last node
	int size = 0;//the size of the list

	void push(Node<T>*);
	void push(T);
};

template<typename T>
Node<T>* initiate(T*, int);
template<typename T>
void print(Node<T>*);
template<typename T>
void del(Node<T>*);
template<typename T>
void deconstruct(Node<T>*);

int main(){
	int array1[] = {1,2,3,4,5};
	int array2[] = {6,7,8,9,10};
	Node<int>* head1 = initiate(array1, 5);
	Node<int>* head2 = initiate(array2, 5);
	
	Node<int>* temp = head1;
	while(temp->next != NULL){
		temp = temp->next;
	}
	//use temp to find the last node of list1
	
	temp->next = head2;//combine list1 and list2
	
	cout << "the list is as following" << endl;
	print(head1);
	print(head2);
	del(head2);
	cout << "after deleting head2, the list is as following" << endl;
	print(head1);
	deconstruct(head1);

	cout << "another test" << endl;
	myList<char> head3;
	head3.push('a');
	head3.push('b');
	head3.push('c');
	head3.push('d');
	Node<char>* e = new Node<char>('e');
	head3.push(e);
	head3.push('f');
	head3.push('g');

	cout << "the list is as following:" << endl;
	print(head3.head);
	del(e);
	cout << "after deleting e, the list is as following:" << endl;
	print(head3.head);
	deconstruct(head3.head);
}

template<typename T>
Node<T>* initiate(T* array, int n){
	Node<T> *head = new Node<T>(array[0]);
	Node<T> *temp = head;
	for(int i = 1; i < n; i++){
		temp->next = new Node<T>(array[i]);
		temp = temp->next;
	}
	return head;
}

template<typename T>
void print(Node<T>* head){
	Node<T>* temp = head;
	while(temp != NULL){
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

template<typename T>
void del(Node<T>* NodeDel){
//we can impletement this by copying 
//the next node data of NodeDel to NodeDel
//then deleting the next node of NodeDel
	if(NodeDel->next == NULL){
	//this method will have one drawback
	//that is it isn't applicabel to the
	//case that NodeDel is the last node
	//here I directly delete it. Another
	//option is to set it as a dummy variable
		delete NodeDel;
	}
	else{
		Node<T>* temp = NodeDel->next;
		NodeDel->data = temp->data;
		NodeDel->next = temp->next;
		delete temp;
	}
}

template<typename T>
void deconstruct(Node<T>* head){
	Node<T>* runner;
	while(head != NULL){
		runner = head->next;
		delete head;
		head = runner;
	}
}

template<typename T>
void myList<T>::push(Node<T> *in){
	if(size == 0){
		head = in;
		end = in;
		size++;
	}
	else{
		end->next = in;
		end = in;
		size++;
	}
}

template<typename T>
void myList<T>::push(T in){
	Node<T>* a = new Node<T>(in);
	if(size == 0){
		head = a;
		end = a;
		size++;
	}
	else{
		end->next = a;
		end = a;
		size++;
	}
}
