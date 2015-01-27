#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class Solution{
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
		dict.emplace(start);
		dict.emplace(end);
		unordered_map<string, vector<string>> from;
		queue<string> que;
		que.push(start);
		dict.erase(start);

		int endLevel = -1;
		int level = 0;
		
		while(!que.empty()){
			if(endLevel != -1) break;
			int size = que.size();
			unordered_set<string> toPush;//this is acctually what the next level is
			for(int ttt = 0; ttt < size; ttt++){
				string front = que.front();
				if(front == end){
					endLevel = level;
					break;
				}

				for(unsigned int i = 0; i < front.size(); i++){
					string neighbor = front;
					for(int j = 0; j < 26; j++){
						neighbor[i] = (char)((int)'a' + j);
						if(neighbor == front) continue;
						
						if((dict.count(neighbor) != 0)){
							from[neighbor].push_back(front);
							//very important trick here: keep track of where the neighbor
							//is from. This will improve the backtrack process since all
							//the string we trace back from end will lead us back to nothing but start,
							//we can avoid a lot of unnecessary check here
							toPush.emplace(neighbor);
						}
					}
				}
				que.pop();
			}
			/*
 * Here is what I don't understand. I firstly use following codes to find neighbors the current string, "front",
 * can "jump" to, by iterating the whole dict. I thought this should be faster than iterating chars in
 * the current string since the iterating the whole dict will take O(dict.size() * each level's size * length of string)
 * while above code takes O(26^length fo string) in time, which should be much greater than the first one.
 * However, I failed with the following case. Can anyone explain the reason, please?
				string front = que.front();
				dict.erase(front);
				if(front == end){
					endLevel = level;
					break;
				}
				else{
					for(unordered_set<string>::iterator itr = dict.begin(); itr != dict.end(); itr++){
						string neighbor = *itr;
						if(help2(neighbor, front)){
							from[neighbor].push_back(front);
							toPush.emplace(neighbor);
						}
					}
				}
				que.pop();
			}
			*/

			level++;
			for(unordered_set<string>::iterator itr = toPush.begin(); itr != toPush.end(); itr++){
				string temp = *itr;
				que.push(temp);
				dict.erase(temp);
				//every time after next level is determined, erase them from dict
				//since they won't be at the next next level(we need to exclude them from the future check)
			}
		}

		vector<vector<string>> result;
		if(from[end].size() == 0) return result;
		vector<string> tempRes;

		tempRes.push_back(end);
		help(result, tempRes, endLevel, start, end, from);
		return result;
    }
	
	void help(vector<vector<string>>& result, vector<string>&tempRes, int level, string& start, string& end, unordered_map<string, vector<string>>& from){
//this is the backtracking function
//actually level here is not needed since the last word will always be start
//but I'm just too tired to modify it
		if(level == 0){
			vector<string> toPush;
			for(int i = (int)tempRes.size() - 1; i >= 0; i--){
				toPush.push_back(tempRes[i]);
			}
			result.push_back(toPush);

			return;
		}

		for(unsigned int i = 0; i < from[end].size(); i++){
			string neighbor = from[end][i];
			tempRes.push_back(neighbor);
			help(result, tempRes, level - 1, start, neighbor, from);
			tempRes.pop_back();
		}
	}

	bool help2(string& s1, string& s2){
//this is used to see if s1 and s2 are neighbors to each other
		if(s1.size() != s2.size()) return false;
		int count = 0;
		for(unsigned int i = 0; i < s1.size(); i++){
			if(s1[i] != s2[i]) count++;
			if(count > 1) return false;
		}
		if(count == 0) return false;
		return true;
	}
};

int main(){
	string start = "red";
	string end = "tax";
	unordered_set<string> dict = {"ted","tex","red","tax","tad","den","rex","pee"};
	Solution soln;
	vector<vector<string>> result = soln.findLadders(start, end, dict);
	for(unsigned int i = 0; i < result.size(); i++){
		for(unsigned int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
