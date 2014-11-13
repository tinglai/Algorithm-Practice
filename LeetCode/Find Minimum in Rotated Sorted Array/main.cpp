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

int main(){
	vector<int> num = {4,5,6,7,0,1,2};
	Solution solt;
	int result = solt.findMin(num);
	cout << result << endl;
}
