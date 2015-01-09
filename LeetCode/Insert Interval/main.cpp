#include <iostream>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
		if(intervals.empty()){
			result.push_back(newInterval);
			return result;
		}
		Interval merge;
		//merge is the interval that merge those overlaped intervals
		//after inserting newInterval

/*the main job of this problem is to find correct merge
we start from finding merge.start
*/

		if(intervals.back().end < newInterval.start){
		//if the biggest number of the intervals is smaller than newInterval.start
		//then the merge interval will simply be the newInterval and we are done
		//by adding the intervals together into result
			merge = newInterval;
			result = intervals;
			result.push_back(merge);
			return result;
		}
		unsigned int i;
		for(i = 0; i < intervals.size(); i++){
		//find the start of the merge interval which will either be the newInterval.start
		//or intervals[i].start for some i
			if(intervals[i].end < newInterval.start){
				result.push_back(intervals[i]);
			}
			else{
				if(intervals[i].start <= newInterval.start){
					merge.start = intervals[i].start;
				}
				else{
					merge.start = newInterval.start;
				}
				break;
			}
		}
		if(intervals.back().end <= newInterval.end){
			merge.end = newInterval.end;
			result.push_back(merge);
			//if the biggest number in the itervals is smaller than the end of newInterval
			//the end of the merge interval should be newInterval.end
		}
		else{
			//if the merge.end is smaller than the largest number of the intervals
			//then we need to find it in similar way as how we find merge.start
			for(; i < intervals.size(); i++){
				if(intervals[i].end > newInterval.end){
					if(intervals[i].start <= newInterval.end){
						merge.end = intervals[i].end;
						i++;
						//in this case, this very current interval should not
						//be added to result
					}
					else{
						merge.end = newInterval.end;
					}
					break;
				}
			}
			result.push_back(merge);
			for(; i< intervals.size(); i++){
				result.push_back(intervals[i]);
			}
		}
		return result;
    }
};

int main(){
	vector<Interval> intervals = {Interval(1, 5)};
	//vector<Interval> intervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)};
	Interval newInterval(6, 8);
	Solution soln;
	vector<Interval> result = soln.insert(intervals, newInterval);
	for(unsigned int i = 0; i < result.size(); i++){
		cout << "[" << result[i].start << ", " << result[i].end << "] ";
	}
	cout << endl;
}
