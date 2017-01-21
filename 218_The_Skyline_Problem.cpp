//218. The Skyline Problem
//A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
//The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//Notes:
//The number of buildings in any input list is guaranteed to be in the range [0, 10000].
//The input list is already sorted in ascending order by the left x position Li.
//The output list must be sorted by the x position.
//There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int> coordinates;
        for (auto i : buildings){
        	coordinates.insert(make_pair(i[0], i[2]));
        	coordinates.insert(make_pair(i[1], -i[2]));
        }
        multiset<int> heights;
        heights.insert(0);
        vector<pair<int, int>> result;
        int x = -1, y = 0;
        for (auto i : coordinates){
        	if (x >= 0 && (i.first != x) && (result.empty() || result.rbegin() -> second != y)) result.push_back(make_pair(x, y));
        	if (i.second >= 0) heights.insert(i.second);
        	else heights.erase(heights.find(- i.second));
        	x = i.first;
        	y = *heights.rbegin();
        }
        if (!result.empty()) result.push_back(make_pair(x, 0));
        return result;
    }
};