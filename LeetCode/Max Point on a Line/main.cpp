#include <iostream>
#include <unordered_map>
#include <vector>
#include <cfloat>

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
		if(points.size() <= 2) return (int)points.size();

		unordered_map<int, unordered_map<int, int>> weight;
		int result = 0;
		for(unsigned int i = 0; i < points.size(); i++){
			weight[points[i].x][points[i].y]++;
			if(weight[points[i].x][points[i].y] > result){
				result = weight[points[i].x][points[i].y];
			}
		}

		for(unsigned int i = 0; i < points.size(); i++){
			unordered_map<double, int> count;
			unordered_map<int, int> virtical;
			int n = weight[points[i].x][points[i].y];
			for(unsigned int j = i + 1; j < points.size(); j++){
				if(points[i].x == points[j].x){
					if(points[i].y == points[j].y){
						continue;
					}
					else{
						if(virtical.count(points[i].x) == 0){
							virtical.emplace(points[i].x, 1 + n);
						}
						else virtical[points[i].x]++;
						if(virtical[points[i].x] > result) result = virtical[points[i].x];
					}
				}
				else{
					double slope = ((double)points[i].y - (double)points[j].y) 
							   / ((double)points[i].x - (double)points[j].x);
					if(count.count(slope) == 0) count.emplace(slope, 1 + n);
					else count[slope]++;
					if(count[slope] > result){
						result = count[slope];
cout << "slope = " << slope << endl;
					}
				}
			}
		}
		return result;
    }
};

int main(){
	//vector<Point> points = {Point(0,0), Point(1,1), Point(2,2), Point(1,2)};
	//vector<Point> points = {Point(1, 1), Point(1, 1), Point(1, 1)};
vector<Point> points = {Point(84,250),Point(0,0),Point(1,0),Point(0,-70),Point(0,-70),Point(1,-1),Point(21,10),Point(42,90),Point(-42,-230)};
	Solution soln;
	int result = soln.maxPoints(points);
	cout << "result = " << result << endl;
}
