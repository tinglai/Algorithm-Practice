#include <iostream>
#include <string>

using namespace std;

//void parenthese(int);
void help(int, int, string);

void help(int left, int right, string list){
//left is num of left paren that can be added
//right is num of right paren that can be added
	if(left == 0 && right == 0){
		cout << list << endl;
	}
	else{
		if(left > 0){
			list.push_back('(');
			help(left - 1, right, list);
			list.pop_back();
		}
		if(right > left){
			list.push_back(')');
			help(left, right - 1, list);
		}
	}
}

int main(){
	int n;
	cout << "n = ";
	cin >> n;
	string list;
	help(n, n, list);
}
