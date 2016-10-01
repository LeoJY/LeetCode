//121. Best Time to Buy and Sell Stock
//Say you have an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
 int maxProfit(vector<int> &prices) {
    if(prices.size() < 2) return 0;   
    int min = prices[0];
    int profit = 0;
    for (int i=1; i<prices.size(); ++i)
    {
        if ( prices[i] - min > profit)
        {
            profit = prices[i] - min;
        }
       if (prices[i] < min)
        {
            min = prices[i];
        }
        
    }
    return profit;
    }
};

int main()
{
	Solution testcase;

	cout << "input the test case array size:" << endl;
	int testarraysize;
	cin >> testarraysize;

	cout << "input the test case array:" << endl;
	int testarray[testarraysize];
	for (int i = 0; i < testarraysize; ++i)
	{
		cout << "please input the " << i+1 << " element:" << endl;
		cin >>testarray[i];
	}

	//generate the vector
	vector <int> testvector(testarray,testarray + testarraysize); 

	int result = testcase.maxProfit (testvector);

	cout << "the max profit is :" << result << endl;


	return 0;
}