#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int maxProfit(vector<int>& prices){
		if(prices.size() <= 1) return 0;
		vector<int> profit1(prices.size()); 
		// profit1[i] means the max profit with the prices
		// starting from prices[0]
		// to prices[i] within one trade
		vector<int> profit2(prices.size());
		// profit1[i] means the max profit with the prices
		// starting from prices[i]
		// to prices.back() within one trade
		int min = prices[0];
		int curProfit = 0;
		for(unsigned int i = 0; i < prices.size(); i++){
			if(prices[i] < min){
				min = prices[i];
			}
			else{
				int tempProfit = prices[i] - min;
				if(tempProfit > curProfit){
					curProfit = tempProfit;
				}
			}
			profit1[i] = curProfit;
		}
		int max = prices.back();
		curProfit = 0;
		for(int i = prices.size() - 1; i >= 0; i--){
			if(prices[i] > max){
				max = prices[i];
			}
			else{
				int tempProfit = max - prices[i];
				if(tempProfit > curProfit){
					curProfit = tempProfit;
				}
			}
			profit2[i] = curProfit;
		}
		int result = 0;
		for(unsigned int i = 0; i < prices.size(); i++){
			int sum = profit1[i] + profit2[i];
			if(sum > result){
				result = sum;
			}
		}
		return result;
	}
};

int main(){
	vector<int> prices = {1,2,3,4,5,1,2,5,4,76,2,3,54,4};
	Solution soln;
	int result = soln.maxProfit(prices);
	cout << "result = " << result << endl;
}
