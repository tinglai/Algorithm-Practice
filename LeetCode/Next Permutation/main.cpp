#include <iostream>
#include <vector>

using namespace std;

class Solution{
//we start the analysis from the back of the vector
//if a subvector (num[k] ~ num[n-1]) has been the biggest number 
//it should be in an order from big to small
//find the first index , k, starting from the back of vector,
//such that num[k + 1] ~ num[n-1] is the biggest number and num[k] < num[k+1]
//then we find the first number in num[k+1] ~ num[n-1] and swap that number
//with num[k], and reserve the order of the swapped subvector, we get the next
//permutation
public:
    void nextPermutation(vector<int> &num){
		if(num.size() < 2) return;

		int size = (int)num.size();
		int idx;
		for(idx = size - 2; idx >= 0; idx--){
			if(num[idx] < num[idx + 1]){
				break;
			}
		}
		if(idx == -1){
		//if idx == -1, then it means that current permutation
		//is the biggest number
			int i = 0;
			int j = size - 1;
			while(i < j){
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
				i++;
				j--;
			}
		}
		else{
			int i = size - 1;
			while(true){
				if(num[i] > num[idx]){
					int temp = num[i];
					num[i] = num[idx];
					num[idx] = temp;
					break;
				}
				i--;
			}
			i = idx + 1;
			int j = size - 1;
			while(i < j){
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
				i++;
				j--;
			}
		}
    }
};

int main(){
	vector<int> num = {1, 1, 5};
	Solution soln;
	soln.nextPermutation(num);
	for(unsigned int i = 0; i < num.size(); i++){
		cout << num[i] << " ";
	}
	cout << endl;
}
