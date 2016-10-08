//122. Best Time to Buy and Sell Stock II
//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
	    int n = prices.size();
	    int result = 0;
	    for (int i = 0; i < n - 1; ++i)
	    {
	    	if (prices[i] < prices[i + 1])
	    	{
	    		result = result + prices[i + 1] - prices[i];
	    	}
	    }
	    return result;
    }
};

int main(){
	Solution testcase;
	int input;
	vector<int> testvector;
	cout << "please input the testvector(EOF = -9999):" << endl;
	while (cin >> input && input != -9999){
		testvector.push_back(input);
	}

	int testresult = testcase.maxProfit(testvector);

	cout << "the result is " << testresult << endl;
	return 0;
}