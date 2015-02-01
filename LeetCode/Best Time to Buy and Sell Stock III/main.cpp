#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
		int lowest = 0, bestBuy = -1, bestSell = -1;
		int profit = 0;
		for(unsigned int i = 1; i < prices.size(); i++){
			if(prices[i] - prices[lowest] > profit){
				bestBuy = lowest;
				bestSell = i;
				profit = prices[i] - prices[lowest];
			}
			if(prices[i] < prices[lowest]){
				lowest = i;
			}
		}
		return profit;
    }
};

int main(){
	//vector<int> prices = {0, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> prices = {};
	Solution soln;
	int result = soln.maxProfit(prices);
	cout << "result = " << result << endl;
}
