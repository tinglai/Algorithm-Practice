#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s){
		stringstream ss;
		ss.str(s);
		string token;
		while(ss){
			ss >> token;
		}
		return token.size();
    }
};

int main(){
	string s = "";
	//string s = "hello world";
	Solution soln;
	int result = soln.lengthOfLastWord(s);
	cout << "result = " << result << endl;
}
