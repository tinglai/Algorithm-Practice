#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		vector<string> translate(strs.size());//translate strs to the 
											  //form of a2b1...(letter + num of the letter)
		//translate
		for(unsigned int i = 0; i < strs.size(); i++){
			vector<int> count(26, 0);//count how many times one letter 
									 //appears in current word
			for(unsigned int j = 0; j < strs[i].size(); j++){
				count[strs[i][j] - 'a']++;
			}
			for(int j = 0; j < 26; j++){
				char letter = char('a' + j);
				translate[i].push_back(letter);
				translate[i].push_back(count[j]);
			}
		}

		//count how many forms appear
		unordered_map<string, int> numOfForm;
		for(unsigned int i = 0; i < translate.size(); i++){
			numOfForm[translate[i]]++;
		}
		for(unsigned int i = 0; i < translate.size(); i++){
			if(numOfForm[translate[i]] > 1){
				result.push_back(strs[i]);
			}
		}
		return result;
    }
};

int main(){
	vector<string> strs = {"abcd", "bcda", "adcb"};
	Solution soln;
	vector<string> result = soln.anagrams(strs);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << ' ';
	}
	cout << endl;
}
