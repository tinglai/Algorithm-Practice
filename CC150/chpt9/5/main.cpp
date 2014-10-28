#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permutate(int, string&, vector<string*>&);
void print(vector<string*>);

int main(){
	string array = "abc";
	//string array = "";
	//a test case to test the reaction of the func when array is empty
	cout << "All the permutations are as follows:" << endl;
	if(array.size() != 0){
		vector<string*> result;
		permutate(0, array, result);
		print(result);
	}
	else{
		cout << "" << endl;
	}
}

void permutate(int a, string& array, vector<string*>& result){
	//assume array is not empty
	if(a == int(array.size() - 1)){
		string* in = new string();
		*in = array[a];
		result.push_back(in);
	}
	else{
		permutate(a + 1, array, result);
		unsigned int size = result.size();
		vector<string*> help;
		for(unsigned int i = 0; i < size; i++){
			for(unsigned int j = 0; j < result[i]->length() + 1; j++){
				string* in = new string(result[i]->substr(0, j) + 
				   array[a] + result[i]->substr(j, result[i]->length() - j));
				help.push_back(in);
			}
			delete result[i];
			result[i] = nullptr;
		}
		result = help;
	}
}

void print(vector<string*> result){
	for(unsigned int i = 0; i < result.size(); i++){
		cout << *(result[i]) << endl;
	}
}
