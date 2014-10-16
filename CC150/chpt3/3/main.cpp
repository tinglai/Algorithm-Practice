#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class StackWithMin{
//use data stack to store data as normal stack
//use minimun data to store minimun. since minimun
//is decreasing as number of data pushing into
//the stack, the top of the minimun stack should be
//the current minimun
//in this case, push(), pop(), minimun() will all be
//O(1) in time, and O(n) in space where n is the
//number of data pushed in the stack
private:
	stack<T> data;
	stack<T> minimun;

public:
	void push(T);
	void pop();
	T top();
	T min();
};


int main(){
	StackWithMin<int> st;
	st.push(1);
	st.push(3);
	st.push(4);
	st.push(1);
	st.push(0);
	st.push(1);

	cout << "the stack is like :" << endl
		 << " 1\n 0 \n 1 \n 4 \n 3 \n 1" << endl;
	cout << "the minimun of the stack = "
		 << st.min() 
		 << ", and the top of the stack = "
		 << st.top() << endl;
	st.pop();
	cout << "after one pop" << endl;
	cout << "the minimun of the stack = "
		 << st.min() 
		 << ", and the top of the stack = "
		 << st.top() << endl;
	st.pop();
	cout << "after one pop" << endl;
	cout << "the minimun of the stack = "
		 << st.min() 
		 << ", and the top of the stack = "
		 << st.top() << endl;
}

template<typename T>
void StackWithMin<T>::push(T in){
	if(minimun.empty()){
	//if minimun is empty, then data will be empty too
		data.push(in);
		minimun.push(in);
	}
	else{
		data.push(in);
		if(minimun.top() >= in){//here = sign is necessary
			minimun.push(in);
		}
	}
}

template<typename T>
void StackWithMin<T>::pop(){
	if(data.empty()){
		cout << "the stack is empty!" << endl;
		exit(1);
	}
	if(data.top() == minimun.top()){
		minimun.pop();
	}
	data.pop();
}

template<typename T>
T StackWithMin<T>::top(){
	return data.top();
}

template<typename T>
T StackWithMin<T>::min(){
	return minimun.top();
}
