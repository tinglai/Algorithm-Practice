#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    void reverseWords(string &s){
		int size = (int)s.size();

		//following codes deal with the spaces in between words
		//not necessary, just to pass the OJ
		size = s.size();
		int fast = 0;
		int slow = 0;
		while(fast < size){
			if(s[fast] != ' '){
				s[slow] = s[fast];
				fast++;
				slow++;
			}
			else{
				if(fast > 0 && s[fast - 1] != ' '){
					s[slow] = s[fast];
					slow++;
					fast++;
				}
				else{
					fast++;
				}
			}
		}
		for(; slow < fast; slow++){
			s.pop_back();
		}
		if(s.back() == ' ') s.pop_back();
/*
 	following codes deal with the reversion
	we firstly reverse all the string, then reverse word by word
	the alogrithm is in O(n) time and O(1) space
*/

		size = s.size();
		for(int i = 0; i < size / 2; i++){
			swap(s[i], s[size - 1 - i]);
		}

		int i = 0;
		int j;
		while(i < size){
			if(s[i] == ' '){
				i++;
				continue;
			}
			j = i + 1;
			while(j < size){
				if(s[j] == ' '){
					int k = j - 1;
					while(i < k){
						swap(s[i], s[k]);
						i++;
						k--;
					}
					break;
				}
				else{
					j++;
				}
			}
			if(j == size){
				int k = j - 1;
				while(i < k){
					swap(s[i], s[k]);
					i++;
					k--;
				}
			}
			i = j + 1;
    	}

	}
};

int main(){
	string s = "the sky is blue";
	//string s = " a b ";
	Solution soln;
	soln.reverseWords(s);
	cout << "s after reversion is: ***" << s << "***" << endl;
}
