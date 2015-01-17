#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/*
 * this is a method that is O(nlogn)
*/
struct myClass{
	bool operator () (const Interval& i, const Interval& j){
		return i.start < j.start;
	}
} myObj;

bool myFunc(const Interval& i, const Interval& j){
	return i.start < j.start;
}

class Solution{
public:
    vector<Interval> merge(vector<Interval> &intervals){
		sort(intervals.begin(), intervals.end(), myObj);
		//sort(intervals.begin(), intervals.end(), myFunc);
		vector<Interval> result;
		if(intervals.empty()) return result;
		Interval curMerge(intervals[0].start, intervals[0].end);
		for(unsigned int i = 1; i < intervals.size(); i++){
			if(intervals[i].start <= curMerge.end){
				//merging is needed
				if(intervals[i].end > curMerge.end){
					curMerge.end = intervals[i].end;
				}
			}
			else{
				//merging is not needed
				result.push_back(curMerge);
				curMerge.start = intervals[i].start;
				curMerge.end = intervals[i].end;
			}
		}
		result.push_back(curMerge);
		return result;
    }
};

int main(){
	vector<Interval> intervals = {Interval(1, 4), Interval(2, 3)};
	Solution soln;
	vector<Interval> result = soln.merge(intervals);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << "[" << result[i].start << ", " << result[i].end << "] ";
	}
	cout << endl;
}
