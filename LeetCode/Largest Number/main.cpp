#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct myComp{
	bool operator() (const int& a, const int& b){
		string aStr = to_string(a);
		string bStr = to_string(b);
		return help(aStr, bStr);
	}
	bool help(string& aStr, string& bStr){
		if(aStr == bStr) return true;
		int sizeAStr = (int)aStr.size();
		int sizeBStr = (int)bStr.size();
		int i = 0;
		while(true){
			if(i == sizeAStr){
			//when the sizes of the strings are different
			//if a.length > b.length and the first b.length
			//chars of both strings are the same
			//what makes a larger than b is that the rest substring
			//of a, the one after b.length, is larger than b
			//in that case, a should be put in front of b
				string temp = bStr.substr(i);
				return help(aStr, temp);
			}
			if(i == sizeBStr){
				string temp = aStr.substr(i);
				return help(temp, bStr);
			}
			if(aStr[i] != bStr[i]){
				return aStr[i] > bStr[i];
			}
			else{
				i++;
			}
		}
	}
}comp;

class Solution{
public:
    string largestNumber(vector<int> &num){
		string result;
		int sum = 0;
		for(unsigned int i = 0; i < num.size(); i++){
			sum += num[i];
		}
		if(sum == 0) return "0";

		sort(num.begin(), num.end(), comp);

		for(unsigned int i = 0; i < num.size(); i++){
			cout << num[i] << endl;
		}
		for(unsigned int i = 0; i < num.size(); i++){
			result += to_string(num[i]);
		}
		return result;
    }
};

int main(){
	//vector<int> num = {3, 30, 34, 5, 9};
	vector<int> num = {824,938,1399,5607,6973,5703,9609,4398,8247};
	Solution soln;
	string result = soln.largestNumber(num);
	cout << "result = " << result << endl;
}
