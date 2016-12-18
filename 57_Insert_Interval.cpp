//57. Insert Interval
//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//You may assume that the intervals were initially sorted according to their start times.

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.empty()) {
        	result.push_back(newInterval);
        	return result;
        }
        int i = 0;
        for (; i < intervals.size(); i++){
        	if (intervals[i].end < newInterval.start) result.push_back(intervals[i]);
        	else if (intervals[i].start > newInterval.end) break;
        	else {
        		newInterval.start = min(newInterval.start, intervals[i].start);
        		newInterval.end = max(newInterval.end, intervals[i].end);
        	}
        }
        result.push_back(newInterval);
        for(; i < intervals.size(); i++){
        	result.push_back(intervals[i]);
        }
        return result;
    }
};


