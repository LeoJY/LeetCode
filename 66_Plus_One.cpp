//66. Plus One
//Given a non-negative number represented as an array of digits, plus one to the number.
//The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	    vector<int> plusOne(vector<int>& digits) {
	    	int n = digits.size();
	    	for (int i = n - 1; i >= 0; --i)
	    	{
	    		if (digits[i] == 9)
	    		{
	    			digits[i] = 0;
	    		}
	    		else
	    		{
	    			digits[i]++;
	    			return digits;
	    		}
	    	}
	    		//the situation when all the digits are 9
	    		digits[0] =1;
	    		digits.push_back(0);
	    		return digits;
	    }
};

int main()
{
	Solution testcase;
	//input the  array

	cout << "input the test case array size:" << endl;
	int testarraysize;
	cin >> testarraysize;

	cout << "input the test case array:" << endl;
	int testarray[testarraysize];
	for (int i = 0; i < testarraysize; ++i)
	{
		cout << "please input the " << i+1 << "th element:" << endl;
		cin >>testarray[i];
	}

	vector <int> testvector(testarray,testarray + testarraysize); 

	vector<int> testresult = testcase.plusOne( testvector );

	for(int i=0;i<=testresult.size()-1;i++)
		{
			cout << testresult[i];
		}
		cout << endl;

}