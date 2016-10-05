//59. Spiral Matrix II
//Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int>>result (n, vector<int>(n));
    	int k = 1, i = 0;
    	while (k <= n * n){
    		int j = i;
    		while (j < n - i) result[i][j++] = k++;
    		j = i + 1;
    		while (j < n - i) result[j++][n - i - 1] = k++;
    		j = n - i - 2;
    		while (j >= i) result[n - i - 1][j--] = k++;
    		j = n - i - 2;
    		while (j > i) result[j--][i] = k++;
    		i ++;
    	}
    	return result;
    }
};

int main()
{
	Solution testcase;
	//input the target value and array
	cout << "input the matrix size n:" << endl;
	int testsize;
	cin >> testsize;
	
	vector<vector<int>> result = testcase.generateMatrix(testsize);

	//show the result
	cout << "the result is: " << endl;
	for (int i = 0; i < testsize; ++i)
	{
		for (int j = 0; j < testsize; ++j)
		{
			cout << result[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}