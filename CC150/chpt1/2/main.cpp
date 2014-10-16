#include <iostream>

using namespace std;

void reverse(char* str){
//firstly use pointers 
	char* end = str;
	while(*end){
		end++;
	}
	end--;
	//end needs to point to the last non-null char
	//so that we can exchange the value of *str and *end
	//otherwise the first char of the reversed string will
	//be null
	char temp;
	while(str < end){
		temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
}

void reverse2(char* str){
//this is a method using index
//in this way we can avoid changing the initial pointer str
	unsigned int size = 0;
	char* ito = str;
	while(*ito){
		size++;
		ito++;
	}
	char temp;
	for(unsigned int i = 0; i < size / 2; i++){
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
	}
}


int main(){
	char before[] = "abcdefghijklmn";
	for(unsigned int i = 0; i < 14; i++){
		cout << before[i];
	}
	cout << endl;
	reverse(before);
	//cout << before[0] << endl;
	for(unsigned int i = 0; i < 14; i++){
		cout << before[i];
	}
	cout << endl;
	reverse2(before);
	for(unsigned int i = 0; i < 14; i++){
		cout << before[i];
	}
	cout << endl;
}
