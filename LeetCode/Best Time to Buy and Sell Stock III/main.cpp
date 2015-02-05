#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
		if(prices.empty()) return 0;
		int size = (int)prices.size();
		vector<int> firstProfit(size);
		vector<int> secondProfit(size);
		
		firstProfit[0] = 0;
		int min = prices[0];
		for(int i = 1; i < size; i++){
			if(prices[i] < min){
				firstProfit[i] = firstProfit[i - 1];
				min = prices[i];
			}
			else{
				int tempProfit = prices[i] - min;
				if(tempProfit > firstProfit[i - 1]){
					firstProfit[i] = tempProfit;
				}
				else{
					firstProfit[i] = firstProfit[i - 1];
				}
			}
		}

		secondProfit[size - 1] = 0;
		int max = prices[size - 1];
		for(int i = size - 2; i >= 0; i--){
			if(prices[i] > max){
				max = prices[i];
				secondProfit[i] = secondProfit[i + 1];
			}
			else{
				int tempProfit = max - prices[i];
				if(tempProfit > secondProfit[i + 1]){
					secondProfit[i] = tempProfit;
				}
				else{
					secondProfit[i] = secondProfit[i + 1];
				}
			}
		}

		int profit = 0;
		for(int i = 1; i < size - 1; i++){
			if(firstProfit[i] + secondProfit[i + 1] > profit){
				profit = firstProfit[i] + secondProfit[i + 1];
			}
		}
		if(firstProfit.back() > profit) profit = firstProfit.back();
		return profit;
    }
};

int main(){
	vector<int> prices = {9,8,7,6,5,4,3,2,1};
	//vector<int> prices = {};
	Solution soln;
	int result = soln.maxProfit(prices);
	cout << "result = " << result << endl;
}
