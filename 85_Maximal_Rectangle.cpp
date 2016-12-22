//85. Maximal Rectangle
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int maxArea = 0;
        vector<int> left(col, 0);
        vector<int> right(col, col);
        vector<int> height(col, 0);
        for (int i = 0; i < row; i ++){
        	int curleft = 0, curright = col;
        	for (int j = 0; j < col; j ++){
        		if (matrix[i][j] == '1') height[j] ++;
        		else height[j] = 0;
        	}
        	for (int j = 0; j < col; j ++){
        		if (matrix[i][j] == '1') left[j] = max(left[j], curleft);
        		else{
        			curleft = j + 1;
        			left[j] = 0;
        		}
        	}
        	for (int j = col - 1; j >= 0; j--){
        		if (matrix[i][j] == '1') right[j] = min(right[j], curright);
        		else{
        			curright = j;
        			right[j] = col;
        		}
        	}
        	for (int j = 0; j < col; j++){
        		maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        	}
        }
        return maxArea;
    }
};


