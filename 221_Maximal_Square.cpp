//221. Maximal Square
//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	int n = matrix.size();
    	if (n == 0) return 0;
    	int m = matrix[0].size();
    	int pre = 0, maxsize = 0;
    	vector<int> temp(m + 1, 0);
    	for (int i = 0; i < n; i ++){
    		for (int j = 1; j < m + 1; j++){
    			int x = temp[j];
    			if (matrix[i][j - 1] == '0') temp[j] = 0;
    			else{
    				temp[j] = min(temp[j], min(temp[j - 1], pre)) + 1;
    				maxsize = max(maxsize, temp[j]);
    			}
    			pre = x;
    		}
    	}
    	return maxsize * maxsize;
    }
};

int main(){
	Solution testcase;
	int testRow, testCol;
	vector<vector<char>> testmatrix;
	cout << "please input the testRow" << endl;
	cin >> testRow;
	cout << "please input the testCol" << endl;
	cin >> testCol;
	for (int i = 0; i < testRow; ++i)
	{
		vector<char> testChar;
		for (int j = 0; j < testCol; ++j)
		{
			char temp;
			cout << "please input matrix[" << i << "][" << j << "]" << endl;
			cin >> temp;
			testChar.push_back(temp);
		}
		testmatrix.push_back(testChar);
	}
	int testResult = testcase.maximalSquare(testmatrix);
	cout << "the result is " << testResult << endl;
	return 0;
}



