#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
		if(s.empty()) return true;
		return help(0, (int)s.size() - 1, s);
    }
	bool help(int a, int b, string& s){
		while(a <= b){
			while(!((s[a] >= 'a' && s[a] <= 'z') 
					   || (s[a] >= 'A' && s[a] <= 'Z')
					   || (s[a] >= '0' && s[a] <= '9')) && a < (int)s.size()){
				a++;
			}
			while(!((s[b] >= 'a' && s[b] <= 'z') 
					   || (s[b] >= 'A' && s[b] <= 'Z')
					   || (s[b] >= '0' && s[b] <= '9')) && b >= 0){
				b--;
			}
			char A, B;
			if(s[a] <= 'Z' && s[a] >= 'A') A = s[a] + 32;
			else A = s[a];
			if(s[b] <= 'Z' && s[b] >= 'A') B = s[b] + 32;
			else B = s[b];
// cout << "A = " << A << " B = " << B << endl;
			if(A != B) return false;
			a++;
			b--;
		}
		return true;
	}
};

int main(){
	//string s = "A man, a plan, a canal: Panama";
	//string s = "race a car";
	string s = "1a2";
	Solution soln;
	bool result = soln.isPalindrome(s);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
