#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		int i1 = 0;
		int i2 = 0;
	
		int size1 = version1.size();
		int size2 = version2.size();
		
		while(i1 < size1 || i2 < size2){
			vector<int> v1;//digits before '.' or till the end of version 1
			vector<int> v2;//digits before '.' or till the end of version 2
			i1 = read(i1, version1, v1);
			i2 = read(i2, version2, v2);
			int result = compare(v1, v2);
			if(result != 0){return result;}
			i1++;
			i2++;
		}
		return 0;
    }

	int read(int i, string& version, vector<int>& v){
		int size = version.size();
		while(version[i] != '.' && i < size){
			int temp = (int)version[i] - (int)'0';
			if(temp == 0 && v.empty()){
				i++;
				continue;
			}
			else{
				v.push_back(temp);
				i++;
			}
		}
		if(v.empty()){
			v.push_back(0);
		}
		return i;
	}

	int compare(vector<int>& v1, vector<int>& v2){
		if(v1.size() > v2.size()) return 1;
		else if(v1.size() < v2.size()) return -1;
		else{
			for(unsigned int i = 0; i < v1.size(); i++){
				if(v1[i] > v2[i]){
					return 1;
				}
				else if(v1[i] < v2[i]){
					return -1;
				}
			}
			return 0;
		}
	}
};

int main(){
	string version1 = "1.1";
	string version2 = "1.10";
	Solution soln;
	int result = soln.compareVersion(version1, version2);
	cout << "the result = " << result << endl;
}
