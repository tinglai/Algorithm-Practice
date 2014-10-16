#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

bool isPerm(string str1, string str2){
	if(str1.length() != str2.length()) 
		return false;

	unordered_map<char, int> countList;

	//firstly count how many times each charactor
	//appears in str1 
	for(unsigned int i = 0; i < str1.size(); i++){
		if(countList.count(str1[i]) == 0){
			countList.emplace(str1[i], 0);
		}
		else
			countList[str1[i]]++;
	}

	//now check charactors in str2
	for(unsigned int i = 0; i < str2.size(); i++){
		if(countList.count(str2[i]) == 0){
			return false;
		}
		else{
			countList[str2[i]]--;
		}
	}
	
	return true;
}

int main(){
	string str1 = "aabbcc";
	string str2 = "abccab";
	if(isPerm(str1, str2))
		cout << "str1 is a permutation of str2" << endl;
	else
		cout << "str1 is not a permutation of str2" << endl;
}
