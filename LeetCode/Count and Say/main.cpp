#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		string result;
		if(n <= 0) return result;
		deque<int> container;
		container.push_back(1);
		int count;
		int val;
		int lastElt;
		unsigned int size;
		for(int i = 0; i < n - 1; i++){
			size = container.size();
			lastElt = container.front();
			count = 0;
			for(unsigned int j = 0; j < size; j++){
				val = container.front();
				container.pop_front();
				if(val == lastElt){
					count++;
				}
				else{
					container.push_back(count);
					container.push_back(lastElt);
					lastElt = val;
					count = 1;
				}
			}
			container.push_back(count);
			container.push_back(lastElt);
		}
		size = container.size();
		for(unsigned int i = 0; i < size; i++){
		string temp;
		temp = to_string(container.front());
		result += temp;
		container.pop_front();
		}
		return result;
    }
};

int main(){
	int n;
	cout << "n = ";
	cin >> n;
	Solution solt;
	string result = solt.countAndSay(n);
	cout << result << endl;
}
