#include <iostream>
#include <string>

using namespace std;

//check if str2 is a rotation of str1
bool isRotate(string &str1, string &str2){
	string doubleStr1 = str1;
	doubleStr1.append(str1);
	if(str1.length() == str2.length()
	      &&doubleStr1.find(str2) != string::npos){
		return true;
	}
	else
		return false;
}

int main(){
	string str1 = "abcdefg";
	string str2 = "efgabcd";
	if(isRotate(str2, str2)){
		cout << "str2 is a rotation of str1." << endl;
	}
	else{
		cout << "str2 is not a rotation of str1." << endl;
	}
}
