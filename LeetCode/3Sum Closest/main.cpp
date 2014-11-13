#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
//In this implementation, I firstly sort the vector, num, then fix
//one int in out loop each time and try to find the possible results among the
//ints in the subvector after the fixed int,
//by starting from the smallest int, num[p], 
//and the largest int, num[q], in the subvector,
//sum the fixed int and num[p] and num[q], if the sum is smaller than target
//all those sums of the fixed int and num[p] and the rest ints in the subvector
//won't be possible since all of them is smaller than the current sum
//vice versa in the case when the sum is larger than target
		int sum = 0;
		if(num.size() <= 3){
			for(unsigned int i = 0; i < num.size(); i++){
				sum+= num[i];
			}
			return sum;
		}
		
		sort(num.begin(), num.end());
		sum = num[0] + num[1] + num[2];
		int result = sum;
		int minDiff = abs(sum - target);
		int diff;
		unsigned int n = num.size();
		for(unsigned int i = 0; i < n - 2; i++){
			unsigned int p = i + 1;
			unsigned int q = n - 1;
			while(p < q){
				sum = num[i] + num[p] + num[q];
				diff = abs(sum - target);
				if(diff < minDiff){
					result = sum;
					minDiff = diff;
				}
				if(diff == 0){
					return sum;
				}
				if(sum < target){
					p++;
				}
				else{
					q--;
				}
			}
		}
		return result;
    }
};

int main(){
	vector<int> num = {0, 2, 1, -3};
	int target = 1;
	Solution solt;
	int result = solt.threeSumClosest(num, target);
	cout << result << endl;
}
