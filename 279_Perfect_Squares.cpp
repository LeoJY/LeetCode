//279. Perfect Squares
//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	vector<int> square = {0};
    	while (square.size() <= n){
    		int m = square.size(), temp = INT_MAX;
    		for (int i = 1; i * i <= m; ++i)
    		{
    			temp = min (temp, square[m - i * i] + 1);
    		}
    		square.push_back(temp);
    	}
    	return square[n];
    }
};

int main(){
	Solution testcase;
	int testnum;
	cout << "please input the test number" << endl;
	cin >> testnum;
	int testresult = testcase.numSquares(testnum);
	cout << "the result is " << testresult << endl;
	return 0;
}