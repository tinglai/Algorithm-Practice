#include <iostream>
#include <vector>

using namespace std;

int search(int, int,vector<int>&);

int main(){
	vector<int> array = {-1, 0, 1, 2, 4, 6, 7};
	int result = search(0, array.size() - 1, array);
	if(result != -1){
		cout << "The magic index is " << result << endl;
	}
	else{
		cout << "Don't find the magic index" << endl;
	}
}

int search(int a, int b, vector<int>& array){
//this method is kind of similar to binary search
//note that it is very important that in binary
//search the mid point is not taken into account
//in the following search, otherwise some idx issures
//will occur
//the time complexity O(log(n)), space O(log(n))
	int mid = (a + b) / 2;
	if(array[mid] == mid) return mid;
	else if(a == b || a > b){
		return -1;//return -1 means search fails
	}
	else if(array[mid] < mid){
		return search(mid + 1, b, array);
	}
	else return search(a, mid - 1, array);
}
