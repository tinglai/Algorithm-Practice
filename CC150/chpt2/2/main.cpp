#include <iostream>
#include <list>

using namespace std;

template <typename T>

T kthToLast(int k, list<T>& lt){
	typename list<T>::iterator p = lt.begin();
	//typename list<T>::iterator q = lt.begin();
	typedef typename list<T>::iterator Node;
	Node q = lt.begin();
	for(int i = 0; i < k; i++){
		q++;
		if(q == lt.end() && i < k - 1){
			//if q points to lt.end()
		    //when i == k - 1
		    //it is fine 
			cout << "k is greater than"
			     << " or equal to the size of the list"
			     << endl;
			return 0;
		}
	}
	while(q != lt.end()){
		q++;
		p++;
	}
	return *p;
}

int main(){
	char input[] = {'a','b','c','d','e','f','g'};
	list<char> lt(input, input + 7);
	cout << "the list is" << endl;
	list<char>::iterator i = lt.begin();
	while(i != lt.end()){
		cout << *i << ' ';
		i++;
	}
	cout << endl;
	cout << "k = " << endl;
	int k;
	cin >> k;
	cout << "the " << k << "th to last element is: " 
	     << kthToLast(k, lt) << endl;
}
