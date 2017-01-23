//265. Paint House II
//There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
//Note:
//All costs are positive integers.
//Follow up:
//Could you solve it in O(nk) runtime?

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
    	int n = costs.size(), k = costs[0].size();
    	int min1 = 0, min2 = 0;
    	vector<int> dp(k, 0);
    	for (int i = 0; i < n; i ++){
    		int temp1 = min1, temp2 = min2;
    		min1 = INT_MAX, min2 = INT_MAX;
    		for (int j = 0; j < k; j ++){
    			dp[j] = costs[i][j] + (dp[j] == temp1 ? temp2 : temp1);
        		if (dp[j] < min1){
        			min2 = min1;
        			min1 = dp[j];
        		}
        		else min2 = min(min2, dp[j]);
    		}
    	}
    	return min1;
    }
};