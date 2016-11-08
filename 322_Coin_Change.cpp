//322. Coin Change
//You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//Note:
//You may assume that you have an infinite number of each kind of coin.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	vector<int> dp(amount + 1, INT_MAX);
    	dp[0] = 0;
    	for (int i = 1; i <= amount; i ++){
    		for (int j = 0; j < coins.size(); j++){
    			if (coins[j] > i || dp[i - coins[j]] == INT_MAX) continue;
    			dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    		}
    	}
    	return (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};

int main(){
	Solution testcase;
	int testAmount, temp;
	vector<int> testVector;
	cout << "please input the target money" << endl;
	cin >> testAmount;
	cin.ignore();
	cout << "please input the coins of different denominations, seperate with space and end with enter" << endl;
	string testString;
	getline(cin, testString);
	istringstream cinstr(testString);
	while(cinstr >> temp){
		testVector.push_back(temp);
	}
	int testResult = testcase.coinChange(testVector, testAmount);
	cout << "the result is " << testResult << endl;
	return 0;
}