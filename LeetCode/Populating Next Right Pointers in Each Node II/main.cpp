#include <iostream>

using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution{
public:
    void connect(TreeLinkNode *root){
		if(root == NULL) return;
		TreeLinkNode* upperLevelItr = root;
		TreeLinkNode* lowerLevelbegin = NULL;
		TreeLinkNode* lowerLevelItr = NULL;

		while(upperLevelItr){
			//find lowerLevelbegin
			if(upperLevelItr->left != NULL){
				lowerLevelbegin = upperLevelItr->left;
				break;
			}
			else if(upperLevelItr->right != NULL){
				lowerLevelbegin = upperLevelItr->right;
				break;
			}
			else upperLevelItr = upperLevelItr->next;
		}
		
		while(upperLevelItr){
			lowerLevelItr = lowerLevelbegin;
			while(upperLevelItr){
				nextNode(upperLevelItr, lowerLevelItr);
			}
			upperLevelItr = lowerLevelbegin;
			while(upperLevelItr){
				//find lowerLevelbegin
				if(upperLevelItr->left != NULL){
					lowerLevelbegin = upperLevelItr->left;
					break;
				}
				else if(upperLevelItr->right != NULL){
					lowerLevelbegin = upperLevelItr->right;
					break;
				}
				else{
					upperLevelItr = upperLevelItr->next;
				}
			}	
		}
    }

	void nextNode(TreeLinkNode*& upperLevelItr, TreeLinkNode*& lowerLevelItr){
		if(upperLevelItr->left == lowerLevelItr){
			if(upperLevelItr->right){
				lowerLevelItr->next = upperLevelItr->right;
				lowerLevelItr = lowerLevelItr->next;
				return;
			}
		}
		upperLevelItr = upperLevelItr->next; // right subtree
		while(upperLevelItr){
			if(upperLevelItr->left){
				lowerLevelItr->next = upperLevelItr->left;
				lowerLevelItr = lowerLevelItr->next;
				return;
			}
			else{
				if(upperLevelItr->right){
					lowerLevelItr->next = upperLevelItr->right;
					lowerLevelItr = lowerLevelItr->next;
					return;
				}
				else upperLevelItr = upperLevelItr->next;
			}
		}
		lowerLevelItr->next = NULL;
		lowerLevelItr = lowerLevelItr->next;
	}
};

int main(){
	TreeLinkNode* n1 = new TreeLinkNode(0);
	TreeLinkNode* n2 = new TreeLinkNode(2);
	TreeLinkNode* n3 = new TreeLinkNode(4);
	TreeLinkNode* n4 = new TreeLinkNode(1);
	TreeLinkNode* n5 = new TreeLinkNode(3);
	TreeLinkNode* n6 = new TreeLinkNode(-1);
	TreeLinkNode* n7 = new TreeLinkNode(5);
	TreeLinkNode* n8 = new TreeLinkNode(1);
	TreeLinkNode* n9 = new TreeLinkNode(6);
	TreeLinkNode* n10 = new TreeLinkNode(8);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	n4->left = n7;
	n4->right = n8;
	n5->right = n9;
	n6->right = n10;

	Solution soln;
	soln.connect(n1);

	TreeLinkNode* itr1 = n1, *itr2 = n1;
cout << endl;
cout << endl;
cout << endl;
cout << endl;
	while(itr1){
		itr2 = itr1;
		while(itr2){
			cout << itr2->val << " ";
			itr2 = itr2->next;
		}
		cout << endl;
		while(itr1){
			//find lowerLevelbegin
			if(itr1->left != NULL){
				itr1 = itr1->left;
				break;
			}
			else if(itr1->right != NULL){
				itr1 = itr1->right;
				break;
			}
			else itr1 = itr1->next;
		}
	}
}
