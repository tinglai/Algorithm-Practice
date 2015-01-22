#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict){
//assume that both start and end are exclude in dict
//and start can not be transformed to end within one step
//Now we solve this problem using revised Dijkstra's algorithm
//or we can treat the search as level by level traversal
		queue<string> que;
		unordered_map<string, int> memo;
		memo[start] = 1;
		que.push(start);
		dict.insert(end);
		while(!que.empty()){
			for(unsigned int i = 0; i < start.size(); i++){
				string tempStr = que.front();
				for(char j = 'a'; j <= 'z'; j++){
					tempStr[i] = j;
					if(dict.count(tempStr) == 0) continue;
					if(memo.count(tempStr) == 0){
						int dist = memo[que.front()] + 1;
						if(tempStr == end) return dist;
						else{
							que.push(tempStr);
							memo.emplace(tempStr, dist);
						}
					}
				}
			}
			que.pop();
		}
		dict.erase(end);
		return 0;
    }
};

int main(){
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot","dot","dog","lot","log"};

	Solution soln;
	int result = soln.ladderLength(start, end, dict);
	cout << "result = " << result << endl;
}
