//378. Kth Smallest Element in a Sorted Matrix
//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//You may assume k is always valid, 1 ≤ k ≤ n^2.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	int n = matrix.size();
    	int low = matrix[0][0], high = matrix[n - 1][n - 1];
    	while (low < high){
    		int mid = low + (high - low) / 2, count = 0;
    		for (int i = 0; i < n; ++i)
    		{
    			int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    			count += pos;
    		}
    		if (count >= k) high = mid;
    		else low = mid + 1;
    	}
    	return low;
    }
};

int main(){
	Solution testcase;
	int testSize, temp, testTarget;
	cout << "please input the testTarget" << endl;
	cin >> testTarget;
	cout << "please input the size of the matrix" << endl;
	cin >> testSize;
	vector<vector<int>> testMatrix (testSize, vector<int>(testSize, 0));
	for (int i = 0; i < testSize; ++i)
	{
		for (int j = 0; j < testSize; ++j)
		{
			cout << "please input the matrix[" << i << "][" << j << "]" << endl;
			cin >> temp;
			testMatrix[i][j] = temp;
		}
	}
	int testResult = testcase.kthSmallest(testMatrix, testTarget);
	cout << "the result is " << testResult << endl;
	return 0;
}