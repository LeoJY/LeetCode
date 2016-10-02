//169. Majority Element
//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//You may assume that the array is non-empty and the majority element always exist in the array.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//randomization
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int index = rand() % n;
            int number = nums[index];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == number)
                    counts++; 
            if (counts > n / 2) return number;
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

	int result = testcase.majorityElement(testvector);

	cout << "The result is: " << result << endl;

	return 0;
}