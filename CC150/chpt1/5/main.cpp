#include <iostream>
#include <string>

using namespace std;

//firstly calculate the size of compressed string
unsigned int compressCount(string &str){
	unsigned int tempCount = 0;
	unsigned int size = 0;
	char last = str[0];
	for(unsigned int i = 0; i < str.size(); i++){
		if(str[i] == last){
			tempCount++;
		}
		else{
			size = size + 1 + (to_string(tempCount)).size();
			last = str[i];
			tempCount = 1;
		}
	}
	size = size + 1 + (to_string(tempCount)).size();
	return size;
}

string compress(string &str){
	unsigned int compressSize = compressCount(str);
	if(str.length() <= compressSize){
		return str;
	}
/*
	string *myStr = new string;
	char last = str[0];
	int count = 0;
	for(unsigned int i = 0; i < str.size(); i++){
		if(str[i] == last){
			count++;
		}
		else{
			myStr->append(1, last);
			myStr->append(to_string(count));
			count = 1;
			last = str[i];
		}
	}
	myStr->append(1, last);
	myStr->append(to_string(count));
	return *myStr;
*/
	string myStr;
	char last = str[0];
	int count = 0;
	for(unsigned int i = 0; i < str.size(); i++){
		if(str[i] == last){
			count++;
		}
		else{
			myStr.append(1, last);
			myStr.append(to_string(count));
			count = 1;
			last = str[i];
		}
	}
	myStr.append(1, last);
	myStr.append(to_string(count));
	return myStr;

}


int main(){
	string str = "aaaakkkdddhsssssoooopppp";
	cout << str << endl;
	cout << compress(str) << endl;
	string str2 = "aab";
	cout << str2 << endl;
	str = compress(str2);
	cout << str2 << endl;

}
