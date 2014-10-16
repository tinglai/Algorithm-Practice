#include <iostream>

using namespace std;

void replace(string &str, int length){
	int numOfSpace = 0;
	//first count how many spaces there are in the string
	//so that we can determine what size of the revised 
	//string should be
	for(int i = 0; i < length; i++){
		if(str[i] == ' '){
			numOfSpace++;
		}
	}
	//now start from the end of the unrevised and 
	//rewrite the string, in this case we can solve
	//this problem in place without worrying about 
	//overwrite some chars that we haven't visit
	int t = length + 2 * numOfSpace - 1;
		//this is the index of the last char of the revised string
	for(int i = length - 1; i >= 0; i--){
		if(str[i] == ' '){
			str[t] = '0';
			str[t - 1] = '2';
			str[t - 2] = '%';
			t = t - 3;
		}
		else{
			str[t] = str[i];
			t--;
		}
	}
	str[length + 2 * numOfSpace] = '\0';//use '\0' to terminate the string
}

int main(){
	string str = "hao hao xue xi, tian tian xiang shang                                                                   ";
	int length = 40;
	cout << str << endl;
	replace(str, length);
	cout << str << endl;
}
