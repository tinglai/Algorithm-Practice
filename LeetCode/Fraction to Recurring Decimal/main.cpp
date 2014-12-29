#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //string fractionToDecimal(int numerator, int denominator) {
    string fractionToDecimal(long numerator, long denominator) {
		string result;
		if(denominator == 0) return result;
		if(numerator * denominator < 0){
			//result.push_back('-');
			result += '-';
		}

		numerator = abs(numerator);
		denominator = abs(denominator);

		long mod = numerator % denominator;
		long devide = numerator / denominator;
		//result.push_back((char)('0' + devide));
		//the above operation might cause some error when the devide is large
		result += to_string(devide);

		if(mod != 0){
			//vector<int> mods(denominator, 0);
			unordered_map<long, long> mods;
			//*** remark: here I used unordered_map instead of vector
			//to save space (at meanwhile to save time) when the denominator
			//is very large, in which case lots of spots in the vector are
			//unnecessary
			mods.emplace(0, 1);

			result += '.';

			devide = (10 * mod) / denominator;
			result += to_string(devide);
			mods.emplace(mod, result.length() - 1);
			mod = (10 * mod) % denominator;

			while(true){
				if(mods.count(mod) != 0) break;
				//break out when I meet a duplicated mod since when a mod
				//appear twice in the decimal, it means that the denominator
				//can never devide up the numerator, the devision will go on and on
				devide = (10 * mod) / denominator;
				result += to_string(devide);
				mods.emplace(mod, result.length() - 1);

				mod = (10 * mod) % denominator;
			}
			if(mod != 0){
				result.insert(mods[mod], 1, '(');
				result += ')';
			}
		}
		return result;
	}
};

int main(){
	int numerator, denominator;
	cout << "numerator = ";
	cin >> numerator;
	cout << "denominator = ";
	cin >> denominator;
	Solution soln;
	string result = soln.fractionToDecimal(numerator, denominator);
	cout << "result = " << result << endl;
}
