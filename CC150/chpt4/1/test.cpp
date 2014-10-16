#include <iostream>

using namespace std;

void test(int *t){
	*t = 1;
}

int main(){
	int ot = 0;
	int *t = &ot;
	cout << *t << endl;
	cout << ot << endl;
	test(t);
	cout << *t << endl;
	cout << ot << endl;
}
