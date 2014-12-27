#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		int size = num.size();
		if(size == 0) return -1;
		if(size == 1) return 0;
		if(num[0] > num[1]) return 0;
		if(num[size - 1] > num[size - 2]) return size - 1;
		for(unsigned int i = 1; i < num.size() - 1; i++){
			if(num[i] > num[i - 1] && num[i] > num[i + 1]){
				return i;
			}
		}
		return -1;
    }
};

int main(){
	vector<int> num = {1, 2, 3, 1};
	Solution soln;
	int result = soln.findPeakElement(num);
	cout << "one peak number is " << num[result] << endl;
}
