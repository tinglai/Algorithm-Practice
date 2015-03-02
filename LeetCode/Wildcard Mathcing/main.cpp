#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
class Solution{
// there are several ways to solve this problem
// 1. To use DP works, it will either use a double vector (O(M * N) in space)
// where M is the length of s and N is the length of p
// or will run a double loop (O(MN) in time) but use one vector
//
// 2. KMP algorithm
// the problem is equivalent to match substring in p, separated by '*', with
// the string in s. For each matching, we can use KMP algorithm. This will use
// O(N) space for the partial separate table

public:
    bool isMatch(const char *s, const char *p){
	// the main idea of this problem is as follows
	// denote f(i, j) as if if s[0:i] match p[0:j] 
	// when p[j] != '*', f(i, j) = f(i - 1, j - 1) && (p[j] == '?' || p[j] == s[j])
	// when p[j] == '*', f(i, j) = f(i, j - 1) || f(i - 1, j)
	// f(i, j - 1) is the case that p[j] = '*' means nothing (empty char)
	// I simply check f(i - 1, j) here instead of checking all f(m, j) when m is belong [0, i - 1]
	// because if f(i - 1, j) returns true, it means that some string
		int sizeP = 0, sizeS = 0;
		for(const char* i = s; *i != '\0'; i++){
			sizeS++;
		}
		for(const char* i = p; *i != '\0'; i++){
			if(*i == '*' && *(i + 1) == '*') continue;
			sizeP++;
		}
		vector<bool> memo(sizeS + 1, false);
		memo[0] = true;
		vector<bool> temp(memo); // temp is the original memo
		for(int i = 0; i < sizeP; i++){
			// when i == i', memo[j - 1] means if substring of s[0:j - 1] match
			// the subpattern of p[0:i],
			// so to initialize, (when i == -1), means that the subpattern
			// doesn't have anything there, we make all the memo to be false
			// since there is no pattern to match
			// memo[0] = true is a tool set up for corner case s[0:0]
			for(int j = 1; j <= sizeS; j++){
				if(p[i] == '*'){
					memo[j] = temp[j] || memo[j - 1];
					temp[j] = memo[j];
				}
				else{
					memo[j] = temp[j - 1] && (p[i] == '?' || p[i] == s[j]);
					temp[j] = memo[j];
				}
			}
		}
		return memo.back();
    }
};

class Solution {
public:
	bool isMatch(const char* s, const char* p){
		const char* pStar=nullptr; // the most recent '*' position of p
		const char* sMis=nullptr; // the most recent mismatch position of s
		while(*s!='\0'){
			if((*s==*p) || (*p=='?')){
				s++;
				p++;
			}
			else if(*p=='*'){
				pStar=p;
				p++; // then try to treat p as match no chars in s
				sMis=s; // the mismatch position for s
			}
			else if(*pStar!='\0'){
				p=pStar+1;
				s=++sMis; // mismatch position matched by *p='*', most recent mismatch position go by 1
			}
			else return false;
		}
		while(*p=='*')p++; 
		return (*p=='\0');
	}
};
*/

class Solution {
public:
	bool isMatch(const char* s, const char* p){
// main idea:
// before '*' appears, everything is trivial
// just move forward the pointer s and p
// after '*' shows up, 
// I separate the pattern p into some subpatterns, spaced by '*'
// for those subpatterns between '*', to check if s fit the
// first subpattern is equvalent to check if
// that subpattern exist in s
// because '*' can be any char including empty char
// I then find the first substring of s
// that satisfies the first subpattern, update s and go on
// searching for the following subpatterns until the
// last subpattern (here I used KMP algorithm which is
// not quite necessary, I just wanted to have a practice to
// impletment that algorithm)
// At that time I know that the searched substring s
// fits the searched subpattern of p and if I move forward
// pointer s, the fitting still holds (because of *)
// what I want is to make s and p go to '\0' together at the
// same time. For that purpose, I need to keep moving forward
// s and check if s exactly fit the last subpattern of p
// and after that, the problem is solved
// I'm not very sure about the time complexity
// but the KMP algorithm take nearly O(N + M) where N and M
// are the length of s and p correspondingly
// and the last step searching should be O(N + M) so I guess
// the time complexity should be O(N + M)
// the space complexity is O(1)
		const char* lastS = nullptr;
		const char* lastP = nullptr;
		bool star = false;
		while(*s != '\0'){
			if(!star){
				if(*p == '?' || *p == *s){
					p++;
					s++;
				}
				else if(*p == '*'){
					star = true;
					while(*p == '*') p++;
					if(*p == '\0') return true;
					lastS = s;
					lastP = p;
				}
				else return false;
			}
			else{
				if(*p == '*'){
					while(*p == '*') p++;
					if(*p == '\0') return true;
					lastS = s;
					lastP = p;
				}
				else if(*p == '?'){
					s++;
					p++;
				}
				else if(*p != '\0'){
					int n = 0;
					const char* itr = p;
					while(*itr != '\0' && *itr != '*' && *itr != '?'){
						itr++;
						n++;
					}
					if(!help(s, p, n)) return false;
					s += n;
					p += n;
				}
				else{
					if(*lastP != '\0'){
						lastS++;
						s = lastS;
						p = lastP;
					}
					else return false;
				}
			}
		}
		while(*p == '*') p++;
		return *p == '\0';
	}
	bool help(const char*& s, const char*& p, int n){
	// KMP algorithm
		vector<int> table(n, 0);
		buildPartialSeparationTable(p, n, table);
		int idx = 0;// number of chars that match
		while(1){
			if(idx == n) return true;
			if(*(s + idx) == '\0') return false;
			if(*(s + idx) == *(p + idx)){
				idx++;
			}
			else{
				if(idx == 0) s++;
				else{
					s += idx - table[idx - 1];
					idx = 0;
				}
			}
		}
	}
	void buildPartialSeparationTable(const char* p, int n, vector<int>& table){
	// a help function for KMP algorithm
		table.resize(n);
		int longgestPre = 0;
		for(int i = 1; i < n; i++){
			while(longgestPre > 0 && p[longgestPre] != p[i]){
				longgestPre = table[longgestPre - 1];
			}
			if(p[longgestPre] == p[i]){
				table[i] = table[i - 1] + 1;
				longgestPre = table[i];
			}
			else table[i] = 0;
		}
	}
};

int main(){
	//const char* s = "abefcdgiescdfimde";
	const char* s = "hi";
	//const char* s = "baababbaaaaabbababbbbbabaabaabaaabbaabbbbbbaabbbaaabbabbaabaaaaabaabbbaabbabababaaababbaaabaababbabaababbaababaabbbaaaaabbabbabababbbbaaaaaabaabbbbaababbbaabbaabbbbbbbbabbbabababbabababaaababbaaababaabb";
	//const char* p = "ab*cd?i*de";
	const char* p = "*?";
	//const char* p = "*ba***b***a*ab**b***bb*b***ab**aa***baba*b***bb**a*abbb*aa*b**baba**aa**b*b*a****aabbbabba*b*abaaa*aa**b";
	
	Solution soln;
	bool result = soln.isMatch(s, p);
	if(result) cout << "yes" << endl;
	else cout << "no" << endl;
}
