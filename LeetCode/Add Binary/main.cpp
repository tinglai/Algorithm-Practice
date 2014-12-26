#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		vector<int> addSum;
		int idxA = a.length() - 1;
		int idxB = b.length() - 1;//both iterate from the end of the string
		while(idxA >= 0 || idxB >= 0){
			int tempSum;
			if(idxA >= 0 && idxB >= 0){
				tempSum = (a[idxA] - '0') + (b[idxB] - '0');
				addSum.push_back(tempSum);
				idxA--;
				idxB--;
			}
			else if(idxA < 0){
				addSum.push_back((b[idxB] - '0'));
				idxB--;
			}
			else{
				addSum.push_back((a[idxA] - '0'));
				idxA--;
			}
		}

		int more = 0;//jin wei
		int l = addSum.size();
		for(int i = 0; i < l; i++){
			if(addSum[i] + more > 1){
				addSum[i] = (addSum[i] + more) % 2;
				more = 1;
			}
			else{
				addSum[i] = (addSum[i] + more);
				more = 0;
			}
		}
		if(more == 1){
			addSum.push_back(1);
		}

		l = addSum.size();
		string result(l, '1');
		for(int i = 0; i < l; i++){
			result[l - 1 - i] = (char)((int)'0' + addSum[i]);
		}
		return result;
    }
};

int main(){
	string a;
	string b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	Solution soln;
	cout << "a + b = " << soln.addBinary(a, b) << endl;
}
