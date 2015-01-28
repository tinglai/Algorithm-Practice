#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string convert(string s, int nRows){
		string result;
		int size = (int)s.size();
		if(size == 0 || nRows <= 0) return result;
		if(size == 1) return s;
		
		vector<string> rows(nRows);

		int itr = 0;
		while(itr < size){
			for(int i = 0; i < nRows; i++){
				if(itr == size) break;
				rows[i] += s[itr];
				itr++;
			}
			for(int i = nRows - 2; i > 0; i--){
				if(itr == size) break;
				rows[i] += s[itr];
				itr++;
			}
		}
		for(unsigned int i = 0; i < rows.size(); i++){
			result += rows[i];
		}
		return result;
    }
};

int main(){
	string s;
	int nRows;
	cout << "s = "; cin >> s;
	cout << "nRows = "; cin >> nRows;
	Solution soln;
	string result = soln.convert(s, nRows);
	cout << "result = " << result << endl;
}
