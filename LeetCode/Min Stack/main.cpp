#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	stack<int> stk;
	stack<int> minStk;

    void push(int x) {
		stk.push(x);
		if(minStk.empty()){
			minStk.push(x);
		}
		else{
			if(minStk.top() >= x){
				minStk.push(x);
			}
		}
    }
    void pop(){
		if(stk.empty()) return;

		int out = stk.top();
		stk.pop();
		if(minStk.top() == out){
			minStk.pop();
		}
    }
    int top(){
		if(stk.empty()) return 0;
		return stk.top();
    }
    int getMin(){
		if(minStk.empty()) return 0;
		return minStk.top();
    }
};

int main(){
	MinStack mstk;
	mstk.push(5);
	mstk.push(5);
	mstk.push(3);
	mstk.push(2);
	mstk.push(1);
	mstk.push(2);
	mstk.push(3);

	cout << "mstk.top() = " << mstk.top() << endl;
	cout << "mstk.getMin() = " << mstk.getMin() << endl;
	
	mstk.pop();
	mstk.pop();
	mstk.pop();

	cout << "mstk.top() = " << mstk.top() << endl;
	cout << "mstk.getMin() = " << mstk.getMin() << endl;
}
