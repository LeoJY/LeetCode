//435. Non-overlapping Intervals
//Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
//Note:
//You may assume the interval's end point is always bigger than its start point.
//Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
    	if (intervals.size() <= 1) return 0;
    	sort(intervals.begin(), intervals.end(), compare);
    	int pre = intervals[0].end;
    	int result = 0;
    	for (int i = 1; i < intervals.size(); i++){
    		if (intervals[i].start < pre) result ++;
    		else pre = intervals[i].end;
    	}
    	return result;
    }
private:
	static bool compare(Interval a, Interval b){
		return a.end < b.end || (a.end == b.end && a.start < b.start);
	}
};



