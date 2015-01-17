#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution{
public:
    int reverse(int x){
		if(x == 0) return x;

		vector<int> memo;
		//l records how far is the number on the LHS of the decimal pt
		//x you duo shao wei(Chinese)
		while(x != 0){
			int temp = x % 10;
			memo.push_back(temp);
			x = x / 10;
		}

		int l = (int)memo.size();

//check integer overflow
		if(l > 10) return 0;//when l > 10, int over flow;
		int result = 0;
		if(l == 10){
			for(int i = 0 ; i < 9; i++){
				result = result * 10 + memo[i];
			}
			if(memo[0] > 0){
				if(result > INT_MAX / 10) return 0;
				else if(result == INT_MAX / 10){
					if(memo[9] > 7) return 0;
					else{
						result = result * 10 + memo[9];
					}
				}
				else{
					result = result * 10 + memo[9];
				}
			}
			else{
				if(result < INT_MIN / 10) return 0;
				else if(result == INT_MIN / 10){
					if(memo[9] < -8) return 0;
					else{
						result = result * 10 + memo[9];
					}
				}
				else{
					result = result * 10 + memo[9];
				}
			}
			return result;
		}

		for(unsigned int i = 0; i < memo.size(); i++){
			result = result * 10 + memo[i];
		}

		return result;
    }
};

int main(){
	int x;
	cout << "x = ";
	cin >> x;
	Solution soln;
	int result = soln.reverse(x);
	cout << "result = " << result << endl;
}
