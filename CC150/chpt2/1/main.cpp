#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

typedef list<int>::iterator Node;

//use a unordered_set to record if an int has
//been visited in the list
void removeDup(list<int> &lt){
	unordered_set<int> isContained;
	Node i = lt.begin();
	while(i != lt.end()){
		if(isContained.count(*i) == 0){
			isContained.emplace(*i);
			i++;
		}
		else{
			Node temp = i;
			i++;
			lt.erase(temp);
			//since erase() will invalidify the 
			//iterator, in order to keep the 
			//iterator i valid, I use a temp
			//here
		}
	}
}

void removeDupFollowUp(list<int>& lt){
//this method doesn't use buffer, but in this case,
//the time complexity will be O(N^2)
	Node current = lt.begin();
	while(current != lt.end()){
		Node runner = current;
		runner++;
		while(runner != lt.end()){
			if(*runner == *current){
				Node temp = runner;
				runner++;
				lt.erase(temp);
			}
			else{
				runner++;
			}
		}
		current++;
	}
}

void print(list<int>& lt){	
	for(Node i = lt.begin(); i != lt.end();
	    i++){
		cout << *i << ' ';
	}
	cout << endl;
}

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

	list<int> lt2 = lt;
	
	cout << "before removeDup: " << endl;
	print(lt);
	cout << endl;
	removeDup(lt);
	cout << "after removeDup: " << endl;
	print(lt);
	
	cout << "lt2 before removeDupFollowUp: " << endl;
	print(lt2);
	cout << endl;
	removeDupFollowUp(lt2);
	cout << "lt2 after removeDupFollowUp: " << endl;
	print(lt);

}
