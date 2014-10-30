#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static vector<int> blocks = {1, 5, 10, 25};
static vector<unordered_map<int, int>> dictionary(blocks.size() - 1, unordered_map<int, int>());
//this dictionary is used for dynamic programming
//not necessary for block 1 since all of the ways are 1
int count(int, int);

int main(){
	int n;
	cout << "Please enter n = " << endl;
	cin >> n;
	int result; 
	if(n > 0){
		 result = count(n, blocks.size() - 1);
	}
	else{
		result = 0;
	}
	cout << "In total, there are " << result << " ways to represent " << n << " cents" << endl;
}

int count(int n, int blockidx){
//blockidx stores the largest block can be used 
//this mathed basically recurses by counting how many blocks that the blockidx is pointing to
//can be contained in n. I count from the largest blocks which in this case is 25 back to 1
//and when the current block is 1, we can see that there is only one way to present n cents
//when you only have 1 cent as the building blocks
//the space complexity is around O(n) because of the dynamic programming, without which the 
//space complexity is really big, exponentially
//same as time complexity
	if(blockidx == 0){
		return 1;
	}
	else{
		if(dictionary[blockidx - 1].count(n) != 0){
			return dictionary[blockidx - 1][n];
		}
		int num = 0;
		while(n >= 0){
			num += count(n, blockidx - 1);
			n = n - blocks[blockidx];
		}
		return num;
	}
}
