//283. Move Zeroes
//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int count = 0;
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); ++it)
		{
			if (*it == 0)
			{
				count ++;
				nums.erase(it);
				it --;
			}
		}
		while (count --)
		{
			nums.push_back(0);
		}
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

	testcase.moveZeroes(testvector);

	for (int i = 0; i < testvector.size(); ++i)
	{
		cout << testvector[i] << '\t';
	}
	cout << endl;
	return 0;
}