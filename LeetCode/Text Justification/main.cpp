#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> fullJustify(vector<string> &words, int L){
		vector<string> result;
		if(words.empty()) return result;
		//assume L >= every word in vecotr words
		int i = 0;
		int size = (int)words.size();
		while(i < size){
			int length = (int)words[i].size();
			vector<string> toPush;
			toPush.push_back(words[i]);
			if(i == size - 1){
				leftJustify(result, toPush, length, L);
				break;
			}
			i++;
			while(i < size - 1){
				if(length + 1 + (int)words[i].size() <= L){
					toPush.push_back(words[i]);
					length += 1 + (int)words[i].size();
					i++;
				}
				else{
					help(result, toPush, length, L);
					break;
				}
			}

			if(i == size - 1){
				if(length + 1 + (int)words[i].size() > L){
					help(result, toPush, length, L);
					vector<string> tempToPush;
					tempToPush.push_back(words[i]);
					leftJustify(result, tempToPush, (int)words[i].size(), L);
					i++;
					break;
				}
				else{
					toPush.push_back(words[i]);
					length += 1 + (int)words[i].size();
					leftJustify(result, toPush, length, L);
					i++;
					break;
				}
			}
		}
		return result;
    }

	void leftJustify(vector<string>& result, vector<string>& toPush, int length, int L){
		string pushStr = toPush[0];
		for(unsigned int i = 1; i < toPush.size(); i++){
			pushStr += " ";
			pushStr += toPush[i];
		}
		for(int i = 0; i < L - length; i++){
			pushStr += " ";
		}
		result.push_back(pushStr);
	}

	void help(vector<string>& result, vector<string>& toPush, int length, int L){
		if(toPush.size() > 1){
			int digit = (L - length) / ((int)toPush.size() - 1);
			int remain = (L - length) % ((int)toPush.size() - 1);
			string pushStr = toPush[0];
			for(unsigned int j = 1; j < toPush.size(); j++){
				pushStr += " ";
				for(int t = 0; t < digit; t++){
					pushStr += " ";
				}
				if(remain > 0){
					pushStr += " ";
					remain--;
				}
				pushStr += toPush[j];
			}
			result.push_back(pushStr);
		}
		else{
			string pushStr = toPush[0];
			for(int j = 0; j < L - length; j++){
				pushStr += " ";
			}
			result.push_back(pushStr);
		}
	}
};

int main(){
	vector<string> words = {"a", "b"};
	//vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
	int L = 1;
	Solution soln;
	vector<string> result = soln.fullJustify(words, L);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
