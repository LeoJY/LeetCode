///54. Spiral Matrix
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> result;
		int m = matrix.size();
    	if ( m == 0) return result;
		int n = matrix[0].size();
    	if ( n == 0) return result;
    	int i = -1, j = -1, cnt1 = n, cnt2 = m;
    	while (cnt1 > 1 && cnt2 > 1){
    		i++; j++;
    		for (int k = 0; k < cnt1 - 1; ++k) result.push_back(matrix[i][j++]);
    		for (int k = 0; k < cnt2 - 1; ++k) result.push_back(matrix[i++][j]);
    		for (int k = 0; k < cnt1 - 1; ++k) result.push_back(matrix[i][j--]);
    		for (int k = 0; k < cnt2 - 1; ++k) result.push_back(matrix[i--][j]);
    		cnt1 -= 2; cnt2 -= 2;
    	}
    	i++; j++;
    	if (cnt1 == 1)
    	{
    		for (int k = 0; k < cnt2; ++k) result.push_back(matrix[i][j++]);
    	}
    	else if (cnt2 == 1)
    	{
    		for (int k = 0; k < cnt1; ++k) result.push_back(matrix[i++][j]);
    	}
    return result;
  	}
};

int main()
{
	Solution testcase;
	//input the target value and array
	cout << "input the matrix row number m:" << endl;
	int testsizem;
	cin >> testsizem;

	cout << "input the matrix col number n:" << endl;
	int testsizen;
	cin >> testsizen;
	
	vector<vector<int>> matrix(testsizem, vector<int>(testsizen));

	cout << "please input the matrix:" <<endl;
	for (int i = 0; i < testsizem; ++i)
	{
		for (int j = 0; j < testsizen; ++j)
		{
			cout << "please input the matrix [" << i << "][" << j << "]: " << endl;
			cin >> matrix[i][j];
		}
	}
	 

	//call the function
	vector<int> result = testcase.spiralOrder(matrix);

	//show the result
	cout << "the result is: " << endl;
	for(int k = 0; k < result.size(); k++)
	{
		cout << result[k] << endl;
	}
	return 0;
}