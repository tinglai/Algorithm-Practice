#include <iostream>

using namespace std;
//there is an improved algorithm called KMP algorithm.
//can check that out if interested
//here just implement the normal heuristic method

class Solution{
public:
	int strStr(char *haystack, char *needle){
		if(haystack == NULL || needle == NULL){
			return -1;
		}
		int h = 0, n = 0;
		while(haystack[h] != '\0' && needle[n] != '\0'){
			if(haystack[h] == needle[n]){
				n++;
				h++;
			}
			else{
				h = h - n + 1;
				n = 0;
			}
		}
		if(needle[n] == '\0'){
			return h - n;
		}
		else{
			return -1;
		}
	}
};

int main(){
	char haystack[] = "abcdefghijklmn";
	char needle[] = "fghij";
	Solution solt;
	int index = solt.strStr(haystack, needle);
	if(index != -1){
		cout << "the index is " << index << endl;
	}
	else{
		cout << "the haystack doesn't contain needle." << endl;
	}
}
