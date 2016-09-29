//1. Two Sum
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> //used for if statement in main function to compare two vector

using namespace std;

class Solution {
//fot each element, compare with the (target - previous elements)  
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (mapping.count(target - nums[i])) 
            {
                return {mapping[target - nums[i]], i};
            }
            mapping[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main()
{
	Solution testcase;
	vector<int>temp(2, -1);				// {-1, -1} vector used to compare and decide whether it is no match or not
	
	//input the target value and array
	cout << "input the test case target value:" << endl;
	int testtarget;
	cin >> testtarget;
	
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

	//call the twoSum function
	vector<int> testresult = testcase.twoSum( testvector, testtarget);

	//show the result
	if (equal(testresult.begin(), testresult.end(), temp.begin()))
	{
		cout << "no match" << endl;
	}
	else
	{
		cout << "the result is: " << endl;
		for(int i=0;i<=testresult.size()-1;i++)
		{
			cout << testresult[i] << "\t" ;
		}
		cout << endl;
	}
	
	return 0;
}