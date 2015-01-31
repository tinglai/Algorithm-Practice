#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
//there should be no '0' in the beginning, otherwise there is 0 way to decode
    int numDecodings(string s){
		if(s[0] == '0') return 0;
		if(s.size() < 2) return (int)s.size();
		vector<int> memo(s.size());

		memo[0] = 1;

		if(s[1] == '0'){
			if(s[0] <= '2') memo[1] = 1;
			else return 0;
		}
		else{
			if(s[0] == '1') memo[1] = 2;
			else if(s[0] == '2'){
				if(s[1] <= '6') memo[1] = 2;
				else memo[1] = 1;
			}
			else{
				memo[1] = 1;
			}
		}

		for(unsigned int i = 2; i < s.size(); i++){
			if(s[i] == '0'){
				if(s[i - 1] == '0' || s[i - 1] > '2'){
					return 0;
				}
				else{
					memo[i] = memo[i - 2];
				}
			}
			else{
				if(s[i - 1] == '0') memo[i] = memo[i - 1];
				else if(s[i - 1] == '1') memo[i] = memo[i - 2] + memo[i - 1];
				else if(s[i - 1] == '2'){
					if(s[i] <= '6')
						memo[i] = memo[i - 2] + memo[i - 1];
					else
						memo[i] = memo[i - 1];
				}
				else{
					memo[i] = memo[i - 1];
				}
			}
		}
		
		int result = memo.back();
		return result;
    }
};

int main(){
	string s;
	cout << "s = ";
	cin >> s;
	Solution soln;
	int result = soln.numDecodings(s);
	cout << "result = " << result << endl;
}
