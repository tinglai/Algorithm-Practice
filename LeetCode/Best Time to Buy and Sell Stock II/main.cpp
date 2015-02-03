#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
		int profit = 0;
		int i = 0, j = 1;
		int size = (int)prices.size();
		for(; j < size; j++){
			if(prices[i] < prices[j]){
				profit += (prices[j] - prices[i]);
			}
			i = j;
		}
		return profit;
    }
};

int main(){
	vector<int> prices = {1, 3, 5, 6,23, 2, 12,3,5,2,1,23};
	Solution soln;
	int profit = soln.maxProfit(prices);
	cout << "profit = " << profit << endl;
}
