#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution{
public:
    int candy(vector<int> &ratings){
		if(ratings.empty()) return 0;
		vector<int> forward(ratings.size(), 1);
		vector<int> backward(ratings.size(), 1);
		for(unsigned int i = 1; i < ratings.size(); i++){
			if(ratings[i] > ratings[i - 1]){
				forward[i] = forward[i - 1] + 1;
			}
		}
		for(int i = (int)ratings.size() - 2; i >= 0; i--){
			if(ratings[i] > ratings[i + 1]){
				backward[i] = backward[i + 1] + 1;
			}
		}
		int result = 0;
		for(unsigned int i = 0; i < forward.size(); i++){
			result += max(forward[i], backward[i]);
		}
		return result;
    }
};

int main(){
	vector<int> ratings = {2,1};
	Solution soln;
	int result = soln.candy(ratings);
	cout << "result = " << result << endl;
}
