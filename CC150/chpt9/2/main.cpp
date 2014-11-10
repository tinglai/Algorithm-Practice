#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

int num(int, int);
int num_second(int, int);
/*
typedef pair<int, int> Key;
static unordered_map<pair<int, int>, int> paths;
*/
static vector<vector<int>> paths;

int main(){
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	//first version
	//this version using a static double vector
	if(x * y != 0){
		paths.resize(x);
		for(int i = 0; i < x; i++){
			paths[i].resize(y);
		}
	}
	cout << "First version: There are in total " 
		 << num(x, y) << " possible paths." << endl;
	
	//second version
	//this version using a double vector as a reference parameter in the helper function
	cout << "Second version: There are in total " << num_second(x, y) << " possible paths." << endl;
}
//Both of the methods use O(x * y) in space, actually may be more for the recursion stack, but still in
//O(x * y) since it cannot be more than 2 * (x * y) in space
//The time complexity is O(x * y) since we are basically calculating from (x, y) back to (0, 0) and adding
//the right entry and down entry together for the current entry which will only take O(1) in time

int num(int x, int y){
	if(x * y == 0) return 1;
	if(paths[x - 1][y - 1] != 0) return paths[x - 1][y - 1];
	else{
		paths[x - 1][y - 1] = num(x - 1, y) + num(x, y - 1);
		return paths[x - 1][y - 1];
	}
}

int helper(int x, int y, vector<vector<int>>& paths_second){
	if(x * y == 0) return 1;
	if(paths_second[x - 1][y - 1] != 0) return paths_second[x - 1][y - 1];
	else{
		paths_second[x - 1][y - 1] = helper(x - 1, y, paths_second) + helper(x, y - 1, paths_second);
		return paths_second[x - 1][y - 1];
	}
}

int num_second(int x, int y){
	if(x * y == 0) return 1;
	vector<vector<int>> paths_second(x, vector<int>(y, 0));
	return helper(x - 1, y, paths_second) + helper(x, y - 1, paths_second);
}

