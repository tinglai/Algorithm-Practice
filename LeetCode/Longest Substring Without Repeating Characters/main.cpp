#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int length = s.length();
		if(length <= 1) return length;
		unordered_map<char, int> index;
		int i = 0;
		int start = 0;//start is the start of the current substring
		int longestLength = 0;
		while(i < length){
			if(index.count(s[i]) == 0){
			//new char is added
				index.emplace(s[i], i);
				i++;
			}
			else{
			//if current char is not new
				if(index[s[i]] < start){
				//if current char didn't appear after start
				//we just update the index in the unordered_map
					index[s[i]] = i;
				}
				else{
				//if current char appeared once after start
				//and s[i] appears again as the duplicated char
				//then the longest length we can have starting from 
				//the start index is i - start
					int temp = i - start;
					if(temp > longestLength){
						longestLength = temp;
					}
					start = index[s[i]] + 1;
					//after comparing, we update the start point to 
					//the index of 1 + the first index of the set of the duplicated chars
					//because the indices before that can not make the longest length longer
					index[s[i]] = i;
				}
				i++;
			}
		}
		int temp = i - start;
		if(temp > longestLength){
			longestLength = temp;
		}
		return longestLength;
    }
};

int main(){
	string s;
	cout << "s = ";
	cin >> s;
	Solution soln;
	int result = soln.lengthOfLongestSubstring(s);
	cout << "the length of the longest substring of s is " << result << endl;
}
