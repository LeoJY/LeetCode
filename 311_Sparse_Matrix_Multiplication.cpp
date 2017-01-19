//311. Sparse Matrix Multiplication
//Given two sparse matrices A and B, return the result of AB.
//You may assume that A's column number is equal to B's row number.


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rowA = A.size();
        int colA = A[0].size();
        int colB = B[0].size();
        vector<vector<int>> result(rowA, vector<int>(colB, 0));
        for (int i = 0; i < rowA; i++){
        	for (int j = 0; j < colA; j ++){
        		if (A[i][j] == 0) continue;
        		for (int k = 0; k < colB; k++){
        			if (B[j][k] == 0) continue;
        			result[i][k] += A[i][j] * B[j][k];
        		}
        	}
        }
        return result;
    }
};
