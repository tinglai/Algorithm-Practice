#include <list>
#include <iostream>

using namespace std;

typedef list<int>::iterator Node;

int main(){
	int input[] = {9,1,3,3,2,5,4,5,
		       6,2,1,3,4,1,3,5,
		       1,4,6,5,4,6,1,3,
		       1,3,4,1,3,3,4,4,
		       5,6,4,5,6,7,5,4,
		       3,3,4,5,7,6,4,3};
	list<int> lt(input, input + 48);
	lt.push_back(8);
	lt.push_back(1);
	
	for(Node i = lt.begin(); i != lt.end();
	    i++){
		cout << *i << ' ';
	}
	cout << endl;
}
