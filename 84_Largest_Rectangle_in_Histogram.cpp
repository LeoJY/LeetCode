//84. Largest Rectangle in Histogram
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        heights.push_back(0);
        n ++;
        stack<int> myStack;
        int i = 0, j = 0, h = 0;
        int maxSize = INT_MIN;
        while(i < n){
        	if (myStack.empty() || heights[i] > heights[myStack.top()]) myStack.push(i++);
        	else{
        		h = heights[myStack.top()];
        		myStack.pop();
        		j = myStack.empty() ? -1 : myStack.top();
        		maxSize = max(maxSize, h * (i - j - 1));
        	}
        }
        heights.pop_back();
        return maxSize;
    }
};




