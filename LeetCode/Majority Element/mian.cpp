#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &num){
		unordered_map<int, int> memo;
		int n = (int)num.size();
		for(int i = 0; i < size; i++){
			memo[num[i]]++;
			if(memo[num[i]] > (n / 2)) return num[i];
		}
		return 0;
    }
};

int main(){

}
