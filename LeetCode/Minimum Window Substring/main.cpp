#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution{
public:
    string minWindow(string S, string T){
		string result;
		int sizeT = T.size();
		int sizeS = S.size();
		if(sizeS < sizeT) return result;
		if(sizeS == 0) return result;
		unordered_map<char, int> charsOfT;
		for(int i = 0; i < sizeT; i++){
			charsOfT[T[i]]++;
		}

		int minLength = INT_MAX;
		int count = 0;
		unordered_map<char, int> charsOfWindow;
		for(int i = 0, j = 0; i < sizeS; i++){
		//j is the start idx of the window
		//i is the end of the window
		//the idea is firstly to fix j and move i forward, once window[i, j] contains all
		//the chars in T (at this moment, window[j, i] is the shortest window that contains
		//all the chars in T, starting from j), move j forward to find the minimun length fo satisfied window 
		//ending with i, update the result. Then, move j forward by 1.
		//repeat the above steps until i reach to the end of S
			if(charsOfT[S[i]] != 0){
				if(charsOfWindow[S[i]] < charsOfT[S[i]]){
					count++;
				}
				charsOfWindow[S[i]]++;
			}
			while(count == sizeT){
				if(charsOfT[S[j]] == 0){
					j++;
				}
				else{
					if(charsOfWindow[S[j]] > charsOfT[S[j]]){
						charsOfWindow[S[j]]--;
						j++;
					}
					else if(charsOfWindow[S[j]] == charsOfT[S[j]]){
						if(i - j + 1 < minLength){
							result = S.substr(j, i - j + 1);
							minLength = i - j + 1;
						}
						charsOfWindow[S[j]]--;
						j++;
						count--;
					}
				}
			}
		}
		return result;
	}
};

int main(){
	string S, T;
	cout << "S = "; cin >> S;
	cout << "T = "; cin >> T;
	Solution soln;
	string result = soln.minWindow(S, T);
	cout << "result = " << result << endl;
}
