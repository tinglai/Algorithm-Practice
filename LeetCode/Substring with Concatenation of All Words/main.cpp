#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		unordered_map<string, int> dic;
		for(unsigned int i = 0; i < L.size(); i++){
			/*
			if(dic.count(L[i]) == 0){
				dic.emplace(L[i], 1);
			}
			else{
				dic[L[i]]++;
			}
			*/
			dic[L[i]]++;
		}
		unsigned int wordLength = L[0].length();
		unsigned int listLength = L.size() * wordLength;
		
		unordered_map<string, int> check;
		for(unsigned int i = 0; i < S.size() - listLength + 1; i++){
			unsigned int j;
			for(j = 0; j < listLength; j = j + wordLength){
				string temp = S.substr(i + j, wordLength);
				if(dic.count(temp) == 1){
					/*
					if(check.count(temp) == 1){
						check[temp]++;
						if(check[temp] > dic[temp]) break;
					}
					else{
						check.emplace(temp, 1);
					}
					*/
					check[temp]++;
					if(check[temp] > dic[temp]) break;
				}
				else{
					break;
				}
			}
			if(j == listLength){
				result.push_back(i);
			}
			check.clear();
		}
		
		return result;
    }
};

int main(){
	Solution sol;
	string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string> L = {"fooo","barr","wing","ding","wing"};
	vector<int> result = sol.findSubstring(S, L);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << ' ';
	}
	cout << endl;
}
