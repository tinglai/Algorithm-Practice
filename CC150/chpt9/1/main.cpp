#include <iostream>
#include <vector>

using namespace std;

long long runStair(int, vector<long long>&);

int main(){
	int n;
	cout << "how many stairs are there?" << endl;
	cin >> n;
	vector<long long> steps(n, 0);
//the vector is used for dynamic programming
//this can extreamly save calculation
//without this vector to stroe calculated results, the 
//time complexity will be as high as O(3^n)
	steps[1] = 1;
	steps[2] = 2;
	steps[3] = 4;
	long long count = runStair(n, steps);
	if(count != -1){
		cout << "there are " << count << " ways to go up to the top"
		 << endl;
	}
	else{
		cout << "n should be possitive" << endl;
	}
}

long long runStair(int n, vector<long long>& steps){
	if (n < 0)
		return -1;
	if(steps[n] != 0)
		return steps[n];
	switch (n){
		case 0:
			return 0;
/*
		case 1:
		//if n = 1, (1)
			return 1;
		case 2:
		//if n = 2, (2)(1,1)
			return 2;
		case 3:
		//if n = 3, (1,1,1)(1,2)(2,1)(3)
			return 4;
*/
		default:
			steps[n] = runStair(n - 1, steps) + runStair(n - 2, steps)
				      + runStair(n - 3, steps);
			return steps[n];
		//correspondingly, for n > 3, the possible last step for the
		//child will be to go up 1 step, 2 steps, 3 steps
	}
}
