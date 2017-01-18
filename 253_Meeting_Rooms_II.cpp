//253. Meeting Rooms II
//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals.size();
        vector<int> timeline;
        int result = INT_MIN, temp = 0;
        for (auto i : intervals){
        	timeline.push_back(i.start);
        	timeline.push_back(-i.end);
        }
        sort(timeline.begin(), timeline.end(), [](int a, int b){if (abs(a) != abs(b)) return abs(a) < abs(b); else return a < b;});
        for (int i = 0; i < timeline.size(); i++){
        	temp += (timeline[i] > 0 ? 1 : -1);
        	result = max(result, temp);
        }
    	return result;
    }
};

//using map

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> changes;
        for (auto i : intervals) {
            changes[i.start] += 1;
            changes[i.end] -= 1;
        }
        int rooms = 0, maxrooms = 0;
        for (auto change : changes)
            maxrooms = max(maxrooms, rooms += change.second);
        return maxrooms;
    }
};

