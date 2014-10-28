#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int search(int, int,vector<int>&);
int search_followup(int, int,vector<int>&);

int main(){
	vector<int> array = {-1, 0, 1, 2, 4, 6, 7};
	int result = search(0, array.size() - 1, array);
	if(result != -1){
		cout << "The magic index is " << result << endl;
	}
	else{
		cout << "Don't find the magic index" << endl;
	}
	cout << "*** follow up ***" << endl;
	vector<int> array_followup = {-1, 0, 4, 4, 5, 5, 7};
	int result_followup = search_followup(0, array_followup.size() - 1, array_followup);
	if(result_followup != -1){
		cout << "The magic index is " << result_followup << endl;
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

int search_followup(int a, int b, vector<int>& array){
//this is for the array that the elements are not unique (distinct)
	int mid = (a + b) / 2;
	if(array[mid] == mid) return mid;
	else if(a == b || a > b){
		return -1;//return -1 means search fails
	}
	else{
		int right = search_followup(max(mid + 1, array[mid]), b, array);
		if(right != -1){
			return right;
		}
		else{
			return search_followup(a, min(mid - 1, array[mid]), array);
		}
	}
}
