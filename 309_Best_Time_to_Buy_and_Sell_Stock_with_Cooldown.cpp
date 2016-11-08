//309. Best Time to Buy and Sell Stock with Cooldown
//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.empty()) return 0;
    	int rest = 0, buy = - prices[0], sell = INT_MIN;
    	for (int i = 0; i < prices.size(); i ++){
    		int presell = sell;
    		sell = buy + prices[i];
    		buy = max(buy, rest - prices[i]);
    		rest = max(rest, presell);
    	}
    	return max(rest, sell);
    }
};

int main(){
	Solution testcase;
	string testString;
	cout <<"please input the test numbers, seperate with space and end with enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	int temp;
	vector<int> testVector;
	while(cinstr >> temp){
		testVector.push_back(temp);
	}
	int testResult = testcase.maxProfit(testVector);
	cout << "the result is " << testResult << endl;
	return 0;
}

