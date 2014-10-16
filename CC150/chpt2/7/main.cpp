#include <iostream>
#include <stack>

using namespace std;

struct Node{
	int data;
	Node* next = NULL;

	Node(){}
	Node(int in):data(in){}
};

bool isPal(Node*);//loop version with help of stack
Node* initialize(int*, int);
void print(Node*);
bool isPal_recur(Node*, int, Node*&);

int main(){
	int array[] = {1,2,3,4,5,6,4,3,2,1};
	Node* head = initialize(array, 10);
	cout << "the list is as following " << endl;
	print(head);
	if(isPal(head)){
		cout << "the list is palindrome" << endl;
	}
	else{
		cout << "the list is not palindrome" << endl;
	}
	Node* compare = NULL;
	if(isPal_recur(head, 10, compare)){
		cout << "the recursive version checks that the list is palindrome" << endl;
	}
	else{
		cout << "the recursive version checks the list is not palindrome" << endl;
	}
}

bool isPal_recur(Node* head, int length, Node*& compare){
//when length == 1 (odd case) or length == 0 (even case),
//we essentially reach to the middle point and let the pointer compare
//point to the corresponding node
//
//Remark: basically, the two methods are the same. Both of them firstly 
//iterate to the middle point, then, one uses stack to reverse the order
//while another one uses recurse (actually also stack frame) to reverse
//the order  
	if(length == 1){
		compare = head->next;
		return true;
	}
	else if(length == 0){
		if(head == NULL) return false;
		compare = head;
		return true;
	}
	else{
		if(isPal_recur(head->next, length - 2, compare)){
			if(head->data == compare->data){
				compare = compare->next;
				return true;
			}
			else
				return false;
		}
	}
	return false;
}

bool isPal(Node* head){
//firstly add the first half nodes into a stack, at meanwhile
//allocate the first node of the second half using a pointer
//compare the node of the second half iterated by the pointer
//and the first half keeped in the stack
	Node* fast = head;
	Node* slow = head;
	stack<Node*> firstHalf;//record the nodes in the first
						   //half in a reversed order
	while(fast != NULL 
		     && fast->next != NULL){
		cout << "debug info: slow = " << slow->data << endl;
		cout << "debug info: fast = " << fast->data << endl;
		firstHalf.push(slow);
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* first = firstHalf.top();
	Node* second = slow;
	if(fast != NULL)//if size of list is odd, we can skip comparing 
		   		    //the middle node
		   		    //here cannot use fast->next == NULL because
		   		    //in even-size list case, fast == NULL, there is
		   		    //no access to fast->next
	{
		second = slow->next;
	}
	while(second != NULL){
		first = firstHalf.top();
		cout << "debug info: first = " << first->data << endl;
		cout << "debug info: second = " << second->data << endl;
		if(first->data != second->data){
			return false;
		}
		
		firstHalf.pop();
		second = second->next;
	}
	return true;
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
