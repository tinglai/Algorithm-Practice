#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if(matrix.empty()) return 0;
		if(matrix[0].empty()) return 0;
		vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
		int result = 0;
		for(unsigned int i = 0; i < matrix.size(); i++){
			for(unsigned int j = 0; j < matrix[i].size(); j++){
				if(matrix[i][j] == '1'){
					if(i == 0) memo[i][j] = 1;
					else memo[i][j] = memo[i - 1][j] + 1;
				}
			}
			int tempRes = maximalHistogram(memo[i]);
			if(tempRes > result) result = tempRes;
		}
		return result;
	}
	int maximalHistogram(vector<int>& histogram){
	// find the largest area of a given hestogram
		int result = 0;
		vector<int> width;
		vector<int> height;
		for(unsigned int i = 0; i < histogram.size(); i++){
			if(height.empty() || height.back() <= histogram[i]){
				height.push_back(histogram[i]);
				width.push_back(1);
			}
			else{
				int tempMax = 0;
				int tempWidth = 0;
				while(!height.empty() && height.back() >= histogram[i]){
					tempWidth += width.back();
					int area = tempWidth * height.back();
					width.pop_back();
					height.pop_back();
					if(area > tempMax) tempMax = area;
				}
				width.push_back(tempWidth + 1);
				height.push_back(histogram[i]);
				if(tempMax > result) result = tempMax;
			}
		}
		int tempWidth = 0;
		for(int j = (int)height.size() - 1; j >= 0; j--){
			tempWidth += width[j];
			int area = tempWidth * height[j];
			if(area > result) result = area;
		}

		return result;
	}
};

int main(){
	vector<vector<char>> matrix = {
									{'1'}};
/*
									{'1','1','0','0','1','0','1'},
									{'1','0','0','1','1','0','1'},
									{'1','1','1','1','0','1','0'},
									{'1','1','0','0','1','0','1'}
								  };
*/
	Solution soln;
	int result = soln.maximalRectangle(matrix);
	cout << "result = " << result << endl;
}
