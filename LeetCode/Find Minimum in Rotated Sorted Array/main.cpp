#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
		if(num.empty()) return -1;
		int temp = num[0];
		for(unsigned int i = 1; i < num.size(); i++){
			if(num[i] < temp){
				return num[i];
			}
			temp = num[i];
		}
		return num[0];
    }
};

class Solution1 {
//Acctually this can be also implemented using binary search
public:
    int findMin(vector<int> &num) {
		if(num.empty()) return -1;
		int a = 0;
		int b = num.size() - 1;
		if(num[a] < num[b]){
			return num[a];
		}
		return num[help(a, b, num)];
    }
	int help(int a, int b, vector<int> &num){
//this will return the index of the minimun number using binary search
//note: this only works for the case that num[0] is not the minimun num
//since this method assume the minimun number is the only number that
//is smaller than its left number
		if(b - a <= 1){
			if(num[a] < num[b]) return a;
			else return b;
		}
		if(num[(a + b) / 2] < num[(a + b) / 2 - 1]){
			return (a + b) / 2;
		}
		if(num[(a + b) / 2] > num[a]){
			return(help((a + b) / 2, b, num));
		}
		else{
			return(help(a, (a + b) / 2, num));
		}
	}
};



int main(){
	//vector<int> num = {4,5,6,7,0,1,2};
	vector<int> num = {1,2,3};
	Solution solt;
	Solution1 solt1;
	int result = solt.findMin(num);
	int result1 = solt1.findMin(num);
	cout << result << endl;
	cout << result1 << endl;
}
