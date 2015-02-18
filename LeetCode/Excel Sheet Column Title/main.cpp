#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string convertToTitle(int n){
		string result;
		vector<char> result_vec;
		while(1){
			n--;
			char temp = (n % 26 + 'A');
			result_vec.push_back(temp);
			n = n / 26;
			if(n == 0) break;
		}
		for(int i = (int)result_vec.size() - 1; i >= 0; i--){
			result.push_back(result_vec[i]);
		}
		return result;
    }
};

int main(){
	int n;
	cout << "n = "; cin >> n;
	Solution soln;
	string result = soln.convertToTitle(n);
	cout << "result = " << result << endl;
}
