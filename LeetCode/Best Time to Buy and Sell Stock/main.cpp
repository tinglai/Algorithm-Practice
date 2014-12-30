#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int lowestIdx = 0; //index of the lowest price
						   //at first set it to be 0
		int bestBuyIdx = -1;//index of the price for best buy
							//when it is -1, it means that the index
							//has not been set up yet
		int bestSellIdx = -1; //index of the price for best sell
		int profit = 0;
		
		int itr = 0;//current index in the iteration
		int size = prices.size();
		while(itr < size){
			if(prices[itr] < prices[lowestIdx]){
				lowestIdx = itr;
			}
			else{
				if(prices[itr] - prices[lowestIdx] > profit){
					bestSellIdx = itr;
					bestBuyIdx = lowestIdx;
					profit = prices[bestSellIdx] - prices[bestBuyIdx];
				}
			}
			itr++;
		}
		return profit;
    }
};

int main(){
	vector<int> prices = {5,3,1,4,5,6,7,9,1,3,4,8};
	Solution soln;
	int result = soln.maxProfit(prices);
	cout << "the max profit is " << result << endl;
}
