#include <iostream> 
#include <vector> 
using namespace std;

void subset(int, vector<int>&, vector<vector<int>*>&);
void print(vector<vector<int>*>&);

int main(){
	vector<int> array = {1, 2, 3, 4};
	//vector<int> array = {};
	//test case used to test the reaction of the func to the empty set
	vector<vector<int>*> result;
	subset(0, array, result);
	cout << "the total subsets are as follows:" << endl;
	print(result);
}

void subset(int a, vector<int>& array, 
			vector<vector<int>*>& result){
//this method use O(2^n) in time and space,
//mainly because of the replication of vector
//here result is used to store the result and
//array is the original set
	if(a == int(array.size())){
		vector<int>* in = new vector<int>;
		result.push_back(in);
	}
	else{
		subset(a + 1, array, result);
		int size = result.size();
		for(int i = 0; i < size; i++){
			vector<int>* in = new vector<int>(*result[i]);
			in->push_back(array[a]);
			result.push_back(in);
		}
	}
}

void print(vector<vector<int>*>& result){
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i]->size(); j++){
			cout << (*result[i])[j] << ' ';
		}
		cout << endl;
	}
}
