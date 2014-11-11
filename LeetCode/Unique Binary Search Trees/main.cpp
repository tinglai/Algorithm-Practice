#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
		if(n <= 0) return 0;
		vector<int> numbers(n + 1, 0);
		   //numbers[n] is used to store the numbers of unique
		   //BST whose biggest number is n
		   //here numbers[0] = 1
		numbers[0] = 1;
		numbers[1] = 1;
		numbers[2] = 2;
		int result = 0;
		for(int i = 1; i < n + 1; i++){
			result = result + help(i - 1, numbers) * help(n - i, numbers);
			//final result is the sum of the numbers of unique BST
			//whose root is 1 ~ n
			//and the number of unique BSTs with root = i is equal to
			//result of numTrees(i - 1) * numTrees(n - i)
		}
		return result;
    }

	int help(int n, vector<int>& numbers){
	//help returns the number of unique BST whose biggest number is n
		if(numbers[n] != 0){
			return numbers[n];
		}
		else{
			for(int i = 1; i < n + 1; i++){
				numbers[n] = numbers[n] + help(i - 1, numbers) * help(n - i, numbers);
			}
			return numbers[n];
		}
	}
};

int main(){
	int n;
	cout << "n = ";
	cin >> n;
	Solution solt;
	cout << "The number of unique BSTs of n numbers is " << solt.numTrees(n) << endl;
}
