#include <iostream>
#include <stack>

using namespace std;

void hano(int n, stack<int>&, stack<int>&, stack<int>&,
		  stack<int>&, stack<int>&, stack<int>&);
void print(stack<int>);
void stateRepo(stack<int>&, stack<int>&, stack<int>&);

int main(){
	stack<int> origi;
	cout << "how many plates are there?" << endl;
	int k;
	cin >> k;
	for(int i = k; i >= 1; i--){
		origi.push(i);
	}
	stack<int> destination;
	stack<int> buffer;
	stateRepo(origi, buffer, destination);
	
	hano(int(origi.size()), origi, buffer, destination,
			 origi, buffer, destination);
	cout << "*********************" << endl;
	stateRepo(origi, buffer, destination);
}

void hano(int n, stack<int>& origi, 
	      stack<int>& buffer, 
		  stack<int>& destination,
		  stack<int>& st1, 
	      stack<int>& st2, 
		  stack<int>& st3){
//move the first n packs from origi
//to destination using buffer
	if(n > int(origi.size())){
		cout << "origi doesn't have "
		     << n << " plates!" << endl;
		exit(1);
	}
	if(n == 1){
		int temp = origi.top();
		origi.pop();
		if(destination.empty() ||
		   temp < destination.top()){
			destination.push(temp);
stateRepo(st1, st2, st3);
		}
		else{
			cout << "bigger plate cannot on smaller plate" 
				 << endl;
			exit(1);
		}
	}
	else{
		//move the first n-1 plates to buffer
		hano(n-1, origi, destination, buffer,
		     st1, st2, st3);
		//then move the nth plate to destination
		int temp = origi.top();
		origi.pop();
		if(destination.empty() ||
		   temp < destination.top()){
			destination.push(temp);
stateRepo(st1, st2, st3);
		}
		else{
			cout << "bigger plate cannot on smaller plate" 
				 << endl;
			exit(1);
		}
		hano(n-1, buffer, origi, destination,
			 st1, st2, st3);
		//then move the n-1 plates in buffer
		//to destination, using origi as buffer
	}
}

void print(stack<int> s){
	if(s.empty()){
		cout << "the stack is empty right now";
	}
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
}

void stateRepo(stack<int>& st1,
			   stack<int>& st2,
			   stack<int>& st3){
	cout << "state report: " << endl;
	cout << "first stack: " << endl;
	print(st1);
	cout << "second stack: " << endl;
	print(st2);
	cout << "third stack: " << endl;
	print(st3);
	cout << endl;
}
