#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points){
		unordered_map<int, int> xs;
		unordered_map<int, int> ys;
		int result = 0;
		for(unsigned int i = 0; i < points.size(); i++){
			xs[points[i].x]++;
			ys[points[i].y]++;
			if(xs[points[i].x] > result){
				result = xs[points[i].x];
			}
			if(ys[points[i].y] > result){
				result = ys[points[i].y];
			}
		}
		return result;
    }
};

int main(){
	vector<Point> points = {Point(0,0), Point(1,0), Point(2,2), Point(1,2)};
	Solution soln;
	int result = soln.maxPoints(points);
	cout << "result = " << result << endl;
}
