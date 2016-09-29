//27. Remove Element
//Given an array and a value, remove all instances of that value in place and return the new length.
//Do not allocate extra space for another array, you must do this in place with constant memory.
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        vector<int>::iterator search_index;
        
        while ((search_index = find(nums.begin(), nums.end(), val)) != nums.end()) {
            nums.erase(search_index);
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
	Solution testcase;

	//input the value and array
	cout << "input the test case  value:" << endl;
	int testvalue;
	cin >> testvalue;
	
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

	int result;

	result = testcase.removeElement(testvector, testvalue);

	cout << "The result array size is: " << result <<endl;

	if (result == 0)
	{
		cout << "no element lesf" << endl;
	}
	else
	{
		cout << "the result is: " << endl;
		for(int i=0;i<=testvector.size()-1;i++)
		{
			cout << testvector[i] << "\t" ;
		}
		cout << endl;
	}


	return 0;
}