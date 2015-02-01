#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL){}
};

class Solution{
public:
    RandomListNode *copyRandomList(RandomListNode *head){
		//assuming there are no duplicated labels
		if(head == NULL) return NULL;
		RandomListNode* result = new RandomListNode(head->label);
		RandomListNode* itr1 = head;
		RandomListNode* itr2 = result;
		unordered_map<int, RandomListNode*> copiedNodes;//key: label, value: node
		copiedNodes.emplace(itr2->label, result);
		while(1){
			if(itr1->random){
				if(copiedNodes.count(itr1->random->label) != 0){
					itr2->random = copiedNodes[itr1->random->label];
				}
				else{
					RandomListNode* rnd = new RandomListNode(itr1->random->label);
					itr2->random = rnd;
					copiedNodes.emplace(itr1->random->label, rnd);
				}
			}
			if(itr1->next == NULL) break;
			if(copiedNodes.count(itr1->next->label) != 0){
				itr2->next = copiedNodes[itr1->next->label];
			}
			else{
				RandomListNode* nxt = new RandomListNode(itr1->next->label);
				itr2->next = nxt;
				copiedNodes.emplace(itr1->next->label, nxt);
			}
			itr1 = itr1->next;
			itr2 = itr2->next;
		}
		return result;
    }
};

int main(){
	RandomListNode* n1 = new RandomListNode(1);
	RandomListNode* n2 = new RandomListNode(2);
	RandomListNode* n3 = new RandomListNode(3);
	RandomListNode* n4 = new RandomListNode(4);
	RandomListNode* n5 = new RandomListNode(5);
	RandomListNode* n6 = new RandomListNode(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	n1->random = n3;
	n3->random = n1;
	n4->random = n2;
	n5->random = n5;
	n6->random = n1;

	Solution soln;
	RandomListNode* result = soln.copyRandomList(n1);
	RandomListNode* itr = result;
	cout << "copied list (next)" << endl;
	while(itr){
		cout << itr->label << " ";
		itr = itr->next;
	}
	cout << endl;

	itr = result;
	cout << "copied list (random)" << endl;
	while(itr){
		if(itr->random){
			cout << itr->label << " ";
		}
		else{
			cout << "XXX" << " ";
		}
		itr = itr->next;
	}
	cout << endl;
	
	itr = n1;
	cout << "original list (next)" << endl;
	while(itr){
		cout << itr->label << " ";
		itr = itr->next;
	}
	cout << endl;

	itr = n1;
	cout << "original list (random)" << endl;
	while(itr){
		if(itr->random){
			cout << itr->label << " ";
		}
		else{
			cout << "XXX" << " ";
		}
		itr = itr->next;
	}
	cout << endl;
	
}
