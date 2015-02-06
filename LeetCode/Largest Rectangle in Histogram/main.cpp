#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

/*
class Solution{
public:
    int largestRectangleArea(vector<int> &height){
// 0. the basic iteration idea is as follows:
// letting height[i] to be the rightest subrectangle, iterate from height[0]
// to height[i] to find the largest rectangle. In that case, we need to calculate
// N * (N - 1) rectangle and lot of calculations are not needed
//
// 1. One improvement (to save some calculation horozontally):
// it is not necessary to calculate the area using height[i] to be the rightest 
// subrectangle if height[i + 1] >= height[i] since no matter what area it has,
// we can find a larger rectangle using height[i + 1]
//
// 2. Another improvement (to save some calculation virtically):
// when we calculate the max rectangle area using one rectangle as the rightest one,
// we need to trace back to count all the left ones
// However, we can save lot of counting by some manipulation:
// we take a stack to record the height of the rectangles (initially as height),
// when the heights are increasing, or the new height is larger than or equalt to
// the height of top of the stack, we keep pushing the height inside the stack,
// once the new height is less than the top height, we firstly calculate the max
// area using the current top height (following the logic discussed in (improvement 1))
// then, we merge the first some rectangles whose height is higher than the new coming
// height, and the new coming rectangle, into one big rectangle with the height equal
// to the new coming rectangle's height. This is because in the following iteration,
// those heights in the stack can never be reached 
//
// 3. One more improvement (to save more calculation horozontally):
// Actually, when we are at the position that we need to find the largest area using 
// current rectangle as the rightest edge, we only need to calculate the area from
// the right edge to the left until to the last rectangle whose height is greater than
// or equal to the rightest rectangle. We can skip calculating the remaining areas
// because the remaining rectangle has lower height and as long as there will be
// other rectangles on the remaining right side have larger height than those lower ones,
// the largest area using those lower rectangles will be updated. So we just need to
// wait for the last edge whose height is higher than that of the lower ones, we can find 
// the maximum area using those lower ones as the left edge. This improvement actually
// improve the algorithm from O(N^2) to O(N)
//
// The following code only implementing the improvements up to 2
		int result = 0;
		if(height.empty()) return result;
		int size = (int)height.size();
		vector<int> myHeight = {height[0]};
		vector<int> width = {1};
		result = height[0];
		for(int i = 1; i < size; i++){
			if(height[i] >= myHeight.back()){
				myHeight.push_back(height[i]);
				width.push_back(1);
			}
			else{
				int curArea = getArea(myHeight, width);
				if(curArea > result) result = curArea;
				int newWidth = 1;
				while(!myHeight.empty() && myHeight.back() > height[i]){
					myHeight.pop_back();
					newWidth += width.back();
					width.pop_back();
				}
				myHeight.push_back(height[i]);
				width.push_back(newWidth);
			}
		}
		int curArea = getArea(myHeight, width);
		if(curArea > result) result = curArea;
		return result;
    }
	int getArea(vector<int>& myHeight, vector<int>& width){
//return the largest area of rectangle whose rightest subrectangle is the
//last rectangle in the vector myHeight
		int minHeight = INT_MAX;
		int curWidth = 0;
		int maxArea = 0;
		for(int i = (int)width.size() - 1; i >= 0; i--){
			if(myHeight[i] < minHeight) minHeight = myHeight[i];
			curWidth += width[i];
			int curArea = curWidth * minHeight;
			if(curArea > maxArea) maxArea = curArea;
		}
		return maxArea;
	}
};
*/

//following code implements the idea of improvement up to O(N)
class Solution{
public:
    int largestRectangleArea(vector<int> &height){
		int result = 0;
		if(height.empty()) return result;
		vector<int> idxStk;
		result = height[0];
		height.push_back(0);
		int size = (int)height.size();
		int i = 0;
		//for(int i = 0; i < size; i++){
		while(i < size){
			if(idxStk.empty() || height[i] > height[idxStk.back()]){
				idxStk.push_back(i);
				i++;
			}
			else{
				while(!idxStk.empty() && height[i] <= height[idxStk.back()]){
					int minHeight = height[idxStk.back()];
					idxStk.pop_back();
					if(idxStk.empty()) result = max(result, i * minHeight);
					else result = max(result, (i - idxStk.back() - 1) * minHeight);
					//the right edge will always be the highest rectangle
				}
			}
		}
		height.pop_back();
		return result;
    }
};

int main(){
	vector<int> height = {2,1,2};
	Solution soln;
	int result = soln.largestRectangleArea(height);
	cout << "result = " << result << endl;
}
