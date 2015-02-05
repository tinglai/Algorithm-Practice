#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
//can be improved by merging memo and sequence by leting class Node
//contain value, and in that case, there is no need to store key in
//Node
//next time you do it, please revise it
//Also, it is really ugly to handle double-linked chain in this way
//there will be so many bugs and hard to debug
//define some temp variables to store preNode and nextNode and save 
//those insertion, deleting and moving in help function to make the 
//code neat
public:
	class Node{
	public:
		int key;
		Node *next = NULL, *front = NULL;
		Node(int k): key(k){};
	};

	Node* head = NULL;
	Node* back = NULL;
	int cap;
	unordered_map<int, int> memo;
	unordered_map<int, Node*> sequence;

    LRUCache(int capacity){
		cap = capacity;
    }

    int get(int key){
		if(memo.count(key) == 0) return -1;
		if(sequence[key] != head){
			sequence[key]->front->next = sequence[key]->next;
			if(sequence[key] != back) sequence[key]->next->front = sequence[key]->front;
			else back = sequence[key]->front;
			//if(sequence[key] == back) back = sequence[key]->front;
			sequence[key]->front = NULL;
			sequence[key]->next = head;
			head->front = sequence[key];
			head = sequence[key];
		}
		return memo[key];
    }

    void set(int key, int value){
		if(memo.count(key) == 0){
			if((int)memo.size() < cap){
				memo.emplace(key, value);
				Node* in = new Node(key);
				sequence.emplace(key, in);
				in->next = head;
				if(head != NULL){
					head->front = in;
				}
				else back = in;
				head = in;
			}
			else if(cap < 1){
				return;
			}
			else{
				int toDelKey = back->key;
				memo.erase(toDelKey);
				sequence.erase(toDelKey);
				if(back != head){
					Node* temp = back->front;
					temp->next = NULL;
					back->key = key;
					back->next = head;
					back->front = NULL;
					head->front = back;
					head = back;
					back = temp;
				}
				else{
					back->key = key;
				}
				memo.emplace(key, value);
				sequence.emplace(key, head);
			}
		}
		else{
			memo[key] = value;
			if(sequence[key] != head){
				sequence[key]->front->next = sequence[key]->next;
				if(sequence[key] != back) sequence[key]->next->front = sequence[key]->front;
				else back = sequence[key]->front;
				//if(sequence[key] == back) back = sequence[key]->front;
				sequence[key]->front = NULL;
				sequence[key]->next = head;
				head->front = sequence[key];
				head = sequence[key];
			}
		}
    }
};

int main(){
	int capacity = 0;
	LRUCache soln(capacity);
	soln.set(1,1);
	soln.set(2,2);
	soln.set(3,3);
	soln.set(4,4);
	soln.set(5,5);

	cout << "soln.get(0) = " << soln.get(0) << endl;
	cout << "soln.get(1) = " << soln.get(1) << endl;

	soln.set(6,6);
	cout << "soln.get(2) = " << soln.get(2) << endl;
}
