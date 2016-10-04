//48. Rotate Image
//You are given an n x n 2D matrix representing an image.
//Rotate the image by 90 degrees (clockwise).
//Follow up:
//Could you do this in-place?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = i + 1; j < n; ++j)
    		{
    			swap(matrix[i][j], matrix[j][i]);
    		}
    	}
    	for (int k = 0; k < n / 2; ++k)
    	{
    		for (int l = 0; l < n; ++l)
    		{
    			swap(matrix[l][k], matrix[l][n - k - 1]);
    		}
    	}

    }
};

int main()
{
	Solution testcase;
	//input the target value and array
	cout << "input the matrix size:" << endl;
	int testsize;
	cin >> testsize;
	
	vector<vector<int>> matrix;

	cout << "please input the matrix:" <<endl;
	for (int i = 0; i < testsize; ++i)
	{
		int testarray[testsize];
		for (int j = 0; j < testsize; ++j)
		{
			cout << "please input the matrix [" << i << "][" << j << "]: " << endl;
			cin >> testarray[j];
		}
		//generate the vector
		vector <int> testvector(testarray,testarray + testsize);
		matrix.push_back(testvector);
	}
	 

	//call the function
	testcase.rotate(matrix);

	//show the result
	cout << "the result is: " << endl;
	for(int k = 0; k < testsize; k++)
	{
		for (int l = 0; l < testsize; ++l)
		{
			cout << matrix[k][l] << "\t" ;
		}
		cout << endl;
	}
	return 0;
}