//74. Search a 2D Matrix
//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int row = matrix.size();
    	int col = matrix[0].size();
    	int low = 0, high = row * col - 1;
    	while (low < high){
    		int mid;
    		mid = (low + high) / 2;
    		if (matrix[mid / col][mid % col] == target) return true;
    		else if (matrix[mid / col][mid % col] > target) high = mid - 1;
    		else low = mid + 1;
    	}
    	return matrix[low / col][low % col] == target;
    }
};

int main()
{
	Solution testcase;
	int testtarget, testrow, testcol;
	cout << "please input the target value: " << endl;
	cin >> testtarget;
	cout << "please input the matrix row and col:" << endl;
	cin >> testrow >> testcol;
	vector<vector<int>> testmatrix(testrow, vector<int>());
	cout << "please input the matrix:" <<endl;
	for (int i = 0; i < testrow; ++i)
	{
		for (int j = 0; j < testcol; ++j)
		{
			int temp;
			cout << "please input the matrix [" << i << "][" << j << "]: " << endl;
			cin >> temp;
			testmatrix[i].push_back(temp);
		}
	}

	bool result;
	result = testcase.searchMatrix(testmatrix, testtarget);

	if (result) cout << "target found" << endl;
	else cout << "target not found" << endl;

	return 0;
}