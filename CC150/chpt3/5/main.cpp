#include <iostream>
#include <stack>

using namespace std;

template <typename T>
struct myQueue{
	stack<T> st1, st2;
	
	myQueue(){}
	myQueue(T*, int);
	void push(T);
	void pop();
	T top();
	int size();
	void load(stack<T>&, stack<T>&);
};

template <typename T>
void print(myQueue<T>);

int main(){
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	myQueue<int> q(array, 10);
	print(q);
	cout << "the first element in the queue is (should be 1)"
		 << endl;
	cout << q.top() << endl;
	cout << "the size of the queue is " << q.size() << endl;
	cout << "after popping" << endl;
	q.pop();
	cout << "the first element in the queue is (should be 2)"
		 << endl;
	cout << q.top() << endl;
	cout << "the size of the queue is " << q.size() << endl;
}

template <typename T>
myQueue<T>::myQueue(T* array, int n){
	for(int i = 0; i < n; i++){
		st1.push(array[i]);
	}
}

template <typename T>
void myQueue<T>::push(T in){
	st1.push(in);
}

template <typename T>
void myQueue<T>::pop(){
//normally just pop the elements in st2
//when st2 is empty, then the bottom element
//in st1 should be the first element in the
//queue, so I "pour" all the elements in st1
//into st2 and in that case the last element
//in st1 should be the first element of st2
	if(st2.empty()){
		myQueue<T>::load(st2, st1);
		//load st2 using data in st1
		//at meanwhile empty st1
	}
	st2.pop();
}

template <typename T>
T myQueue<T>::top(){
	if(st2.empty()){
		myQueue<T>::load(st2, st1);
	}
	return st2.top();
}

template <typename T>
int myQueue<T>::size(){
	return st1.size() + st2.size();
}

template <typename T>
void myQueue<T>::load(stack<T>& st2, stack<T>& st1){
	while(!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}
}

template <typename T>
void print(myQueue<T> q){
	while(q.size() != 0){
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
}
