#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isUniqueChar(string str){
//This method uses an extra vector of bools to store 
//if corresponding char in the string has been included before. 
//It is O(n) complex in time and needs extra space to store the bools
	if(str.length() > 256) //since an ACSII char has at most 256 possible values
		return false;
	vector<bool> isVisited(256, false);
	for(unsigned int i = 0; i < str.length(); i++){
		if(isVisited[str[i]] == false)
			isVisited[str[i]] = true;
		else
			return false;
	}
	return true;
}

bool isUniqueChar2(string str){
//This method directly uses two loops to check if a char showed before
//It is O(n^2) complex in time and O(1) in space.
	if(str.length() > 256)
		return false;
	for(unsigned int i = 0; i < str.length(); i++){
		for(unsigned int j = i + 1; j < str.length(); j++){
			if(str[i] == str[j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	string t = "asdfghjkl;";
	string t2 = "aaa";
	if(isUniqueChar2(t)){
		cout << "all the characters in the string are unique!\n";
	}
	else
		cout << "not all the characters in the string are unique!\n";
	if(isUniqueChar2(t2)){
		cout << "all the characters in the string are unique!\n";
	}
	else
		cout << "not all the characters in the string are unique!\n";

}
