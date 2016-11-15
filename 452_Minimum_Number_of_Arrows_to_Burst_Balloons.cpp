//452. Minimum Number of Arrows to Burst Balloons
//There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
//An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
    	if(points.size() == 0) return 0;
    	if(points.size() == 1) return 1;
    	auto compare = [](pair<int, int> a, pair<int, int> b){
    		return a.second < b.second || (a.second == b.second && a.first < b.first);
    	};
    	sort(points.begin(), points.end(), compare);
    	int result = 1, pre = points[0].second;
    	for (int i = 1; i < points.size(); i++){
    		if (points[i].first <= pre) continue;
    		else {
    			result ++;
    			pre = points[i].second;
    		}
    	}
    	return result;
    }
};


int main(){
	Solution testCase;
	int temp1, temp2;
	string testString1, testString2;
	vector<pair<int, int>> testVec;
	cout << "please input the start points, seperate with space, end with space" << endl;
	getline(cin, testString1);
	cout << "please input the end points, seperate with space, end with space" << endl;
	getline(cin, testString2);
	istringstream cinstr1(testString1);
	istringstream cinstr2(testString2);
	while (cinstr1 >> temp1 && cinstr2 >> temp2){
		testVec.push_back(make_pair(temp1, temp2));
	}
	int testResult = testCase.findMinArrowShots(testVec);
	cout << "the result is " << endl << testResult << endl;
	return 0;
}








