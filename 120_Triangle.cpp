//120. Triangle
//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	int n  = triangle.size();
    	vector<int> result = triangle[n - 1];
    	for (int i = n - 2; i >= 0; --i)
    	{
    		for (int j = 0; j < triangle[i].size(); ++j)
    		{
    			result[j] = min(result[j], result[j + 1]) + triangle[i][j];
    		}
    	}
    	return result[0];
    }
};

int main(){
	Solution testcase;
	cout << "please input the level number of the triangle: " << endl;
	int n;
	cin >> n;
	vector<vector<int>> testvector;
	for (int i = 1; i < n + 1; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < i ; ++j)
		{
			int input;
			cout << "please input the " << i << " level, the " << j + 1<< "th element: " << endl;
			cin >> input;
			temp.push_back(input);
		}
		testvector.push_back(temp);	
	}
	int testresult;
	testresult = testcase.minimumTotal(testvector);
	cout << "the result is: " << testresult << endl;
	return 0;
}