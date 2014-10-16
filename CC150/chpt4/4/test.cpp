#include <iostream>
#include <vector>

using namespace std;

int main(){
	/*vector<int>* haha = new vector<int>;
	vector<int> haha;
	haha->push_back(1);
	haha->push_back(1);
	haha->push_back(1);
	haha->push_back(1);
	haha->push_back(1);
	haha->push_back(1);
	haha->push_back(1);
	haha->push_back(1);
	for(unsigned int i = 0; i < haha->size(); i++){
		cout << (*haha)[i] << endl;
	}
	vector<int> haha;
	haha.push_back(1);
	haha.push_back(1);
	haha.push_back(1);
	haha.push_back(1);
	haha.push_back(1);
	haha.push_back(1);
	haha.push_back(1);
	haha.push_back(1);
	for(unsigned int i = 0; i < haha.size(); i++){
		cout << (haha)[i] << endl;
	}
	//delete haha;
	*/
	
	vector<int>* a = new vector<int>;
	delete a;
	vector<int>* b = new vector<int>(3,0);
	delete b;
	int* c = new int[2][3];
	delete[] c;
}
