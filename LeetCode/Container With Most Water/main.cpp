#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
public:
    int maxArea(vector<int> &height){
//idea is as follows: from the two ends, i, j, calculate the area
//which is min(height[i], height[j]) * (j - i).
//if height[i] < height[j], then, there is no container, using i as
//one edge, has larger area than current one. So we can exclude edge i.
//the remaining problem is to find the max area using heights from 
//height[i + 1] to height[j]
//in the case height[i] > height[j] is similar
		int n = (int)height.size();
		if(n <= 1) return 0;
		int result = 0;
		int i = 0; int j = n - 1;
		while(i < j){
			int area = (j - i) * min(height[i], height[j]);
			if(area > result) result = area;
			if(height[i] < height[j]) i++;
			else j--;
		}
		return result;
    }
};

int main(){
	vector<int> height = {1, 2, 3, 4, 4};
	Solution soln;
	int result = soln.maxArea(height);
	cout << "result = " << result << endl;
}
