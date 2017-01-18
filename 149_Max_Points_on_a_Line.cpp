//149. Max Points on a Line
// /Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	if (points.size() <= 2) return points.size();
    	int result = -1;
    	for (int i = 0; i < points.size() - 1; i++){
    		int vertical = 1, local = -1, duplicates = 0;
    		map<pair<int, int>, int> myMap;
    		for (int j = i + 1; j < points.size(); j ++){
    			if (points[j].x == points[i].x){
    				if (points[j].y == points[i].y) duplicates++;
    				else vertical ++;
    			}
    			else{
    				int temp = GCD(points[j].y - points[i].y, points[j].x - points[i].x);
    				int dy = (points[j].y - points[i].y) / temp;
    				int dx = (points[j].x - points[i].x) / temp;
    				myMap[make_pair(dy, dx)] = (myMap[make_pair(dy, dx)] == 0 ? 2 : myMap[make_pair(dy, dx)] + 1);
    				local = max(local, myMap[make_pair(dy, dx)]);
    			}
    		}
    		local = max(local + duplicates, vertical + duplicates);
    		result = max(result, local);
    	}
    	return result;
    }
private:
	int GCD(int a, int b){
		while(b != 0){
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
};