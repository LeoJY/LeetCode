//62. Unique Paths
//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//How many possible unique paths are there?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<int> result(n, 1);
    	result[0] = 1;
    	for (int i = 1; i < m; ++i)
    	{
    		for (int j = 1; j < n; ++j)
    		{
    			result[j] += result[j - 1];
    		}
    	}
    	return result[n - 1];
    }
};

int main()
{
	Solution testcase;
	cout << "please input the size of the map:" << endl;
	int m, n;
	cin >> m >> n;
	int result = testcase.uniquePaths(m, n);
	cout << "the result is: " << result << endl;
	return 0;
}