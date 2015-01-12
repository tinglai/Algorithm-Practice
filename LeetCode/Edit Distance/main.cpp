#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int l1 = word1.size();
		int l2 = word2.size();
		vector<vector<int>> dist(l1, vector<int>(l2, -1));
		int result = help(word1, word2, l1, l2, dist);
		return result;
	}
	int help(string& word1, string& word2, int i, int j, vector<vector<int>>& dist){
//help is a function that returns the minimum edit distance to make substring of 
//word1 with length = i and substring of word2 with length = j identical
//dist[i - 1][j - 1] records the result when i, j > 0
//
//the key of this question is to understand following two facts:
//1. it is equivalent to change subword1 and subword2 to make the two strings identical since
//all the operations are invertible
//2. given substring w1 and substring w2, we compare the last char of them, c1 and c2, respectively
//if c1 == c2, then the minimum edit distance = help(word1, word2, i - 1, j - 1, dist) for sure
//if c1 != c2, there are 3 ways to make the two substrings agree on the last char:
//	1) to add c1 at the end of w2, after c2 (equivalent to delete c1 from w1), dist = help(word1, word2, i - 1, j, dist) + 1;
//	2) to add c2 at teh end of w1, after c1 (equivalent to delete c2 from w2), dist = help(word1, word2, i, j - 1, dist) + 1;
//	3) change c1 or c2 to make c1 == c2, dist = help(word1, word2, i - 1, j - 1, dist) + 1;
//among all of above three operations, we find the minimum
		if(i == 0){
			return j;
		}
		if(j == 0){
			return i;
		}	

		if(dist[i - 1][j - 1] != -1){
			return dist[i - 1][j - 1];
		}

		if(word1[i - 1] == word2[j - 1]){
			int temp = help(word1, word2, i - 1, j - 1, dist);
			if(i * j != 0)
				dist[i - 1][j - 1] = temp;
			return temp;
		}

		int candi1 = help(word1, word2, i - 1, j, dist) + 1;
		int candi2 = help(word1, word2, i, j - 1, dist) + 1;
		int candi3 = help(word1, word2, i - 1, j - 1, dist) + 1;
		int temp;
		if(candi1 < candi2){
			if(candi1 < candi3){
				temp = candi1;
			}
			else{
				temp = candi3;
			}
		}
		else{
			if(candi2 < candi3){
				temp = candi2;
			}
			else{
				temp = candi3;
			}
		}
		if(i * j != 0) dist[i - 1][j - 1] = temp;
		return temp;
	}
};

int main(){
	string word1, word2;
	cout << "word1 = ";
	cin >> word1;
	cout << "word2 = ";
	cin >> word2;
	Solution soln;
	int result = soln.minDistance(word1, word2);
	cout << "result = " << result << endl;
}
