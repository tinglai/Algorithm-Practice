#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maximumGap(vector<int> &num){
		int n = num.size();
		if(n < 2) return 0;
		int result = 0;
		int max = num[0], min = num[0];
		for(unsigned int i = 1; i < num.size(); i++){
			if(num[i] < min) min = num[i];
			if(num[i] > max) max = num[i];
		}
		double gap = (double)(max - min) / (double)(n - 1);
		vector<int> bounds(2 * n, -1);
		for(int i = 0; i < n; i++){
			int gapIdx = (int)((num[i] - min) / gap);
			   //num[i] is in the gapIdx th gap
			if(bounds[gapIdx * 2] == -1)
				bounds[gapIdx * 2] = num[i];
			else if(num[i] < bounds[gapIdx * 2])
				bounds[gapIdx * 2] = num[i];
			
			if(bounds[gapIdx * 2 + 1] == -1)
				bounds[gapIdx * 2 + 1] = num[i];
			else if(num[i] > bounds[gapIdx * 2 + 1])
				bounds[gapIdx * 2 + 1] = num[i];
		}
		int upperb = bounds[1];
		for(int i = 1; i < n; i++){
			if(bounds[2 * i] != -1){
				if(bounds[2 * i] - upperb > result)
					result = bounds[2 * i] - upperb;
				upperb = bounds[2 * i + 1];
			}
			
		}
		return result;
    }
};

int main(){
	vector<int> num = {1,3, 5, 7,23,52,12,4};
	Solution soln;
	int result = soln.maximumGap(num);
	cout << "result = " << result << endl;
}
