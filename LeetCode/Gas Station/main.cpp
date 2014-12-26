#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		vector<int> gnl;//gain and loss of gas by traveling from station i to i+1
		for(unsigned int i = 0; i < gas.size(); i++){
			int temp = gas[i] - cost[i];
			gnl.push_back(temp);
		}
		unsigned int i = 0;
		while(i < gnl.size()){
			if(gnl[i] < 0){
				i++;
				continue;
			}
			unsigned int j = travel(i, gnl);
			if(j == i){
				return i;
			}
			else{
				i = j;
			}
		}
		return -1;
    }

	unsigned int travel(unsigned int i, vector<int>& gnl){
		//the gas in the tank starts from 0
		//when the car travels from one station to another
		//the containing gas volumn changes
		//if it is negative at station j, 
		//it means that the gas in the tank can't make the car travel from j to j+1
		//moreover, we can ignore the stations between the beginning station i
		//and the terminating station j because it can be guaranteed that no stations
		//in between can make the car travel past j 
		int tank = 0;//gas in tank
		for(unsigned int j = 0; j < gnl.size(); j++){
			unsigned int idx = (i + j) % gnl.size();
			tank += gnl[idx];
			if(tank < 0){
				return i + j;
			}
		}
		return i;
		//if the tank keep non negative, it means that the car can travel 
		//through the circuit and we return the begining index
	}
};

int main(){
	vector<int> cost = {3,3,3,3,3};
	vector<int> gas = {1,2,3,4,5};
	Solution soln;
	int result = soln.canCompleteCircuit(gas, cost);
	if(result == -1){
		cout << "The car cannot complete the circuit" << endl;
	}
	else{
		cout << "The car can complete the circuit starting from station " << result << endl;
	}
}
