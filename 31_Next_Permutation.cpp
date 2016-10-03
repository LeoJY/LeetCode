//31. Next Permutation
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//The replacement must be in-place, do not allocate extra memory.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int i, j, flag, flag1, min = 2147483647;
        for (i = n - 1; i > 0; --i){
        	if (nums[i] > nums[i - 1])
        	{
        		break;
        	}
        }
        flag = i - 1;
        if (flag == -1){
        	reverse(nums.begin(), nums.end());
        }
        else{
        	for (j = i; j < n; ++j){
	        	if (nums[j] > nums[flag] && min > nums[j])
	        	{
	        		flag1 = j;
	        		min = nums[j];
	        	}
	        }
	        swap(nums[flag], nums[flag1]);
	        sort(nums.begin() + flag + 1, nums.end());
        }
        
    }
};

int main()
{
	Solution testcase;
	vector<int>temp(2, -1);				// {-1, -1} vector used to compare and decide whether it is no match or not
	
	//input the target array	
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
	testcase.nextPermutation(testvector);

	//show the result
	cout << "the result is: " << endl;
	for(int i=0;i<=testvector.size()-1;i++)
	{
	cout << testvector[i] << "\t" ;
	}
	cout << endl;	
	return 0;
}