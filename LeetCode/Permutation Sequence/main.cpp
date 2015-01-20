#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string getPermutation(int n, int k){
		string result;
		if(n == 0) return result;
		if(n == 1) return "1";
		vector<int> numbers;

		for(int i = 0; i < n; i++){
			numbers.push_back(i + 1);
		}

		while(n > 1){
			int fact = factorial(n - 1);
			int idx = (k - 1) / fact;
			//notice that the first char of string is related to k and n
			//because there are fixed (n - 1)! chars behind the 1st char
			//
			//meaning that for every char w, from '1' ~ n (n is a number, like 5), there will be 
			//(n - 1)! strings starting with w
			//
			k = k - fact * idx;
			n--;
			int count = -1;
			unsigned int itr = 0;
			for(; itr < numbers.size(); itr++){
				if(numbers[itr] == 0) continue;
				else{
					count++;
					if(count == idx) break;
				}
			}
			result.push_back((char)((int)('0') + numbers[itr]));
			numbers[itr] = 0;
		}
		for(unsigned int i = 0; i < numbers.size(); i++){
			if(numbers[i] != 0){
				result.push_back((char)((int)('0') + numbers[i]));
				break;
			}
		}
		return result;
    }
		
	int factorial(int n){
		if(n == 1) return 1;
		return n * factorial(n - 1);
	}
};

int main(){
	int n, k;
	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
	Solution soln;
	string result = soln.getPermutation(n, k);
	cout << "result = " << result << endl;
}
