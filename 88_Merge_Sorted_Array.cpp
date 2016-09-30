//88. Merge Sorted Array
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, length = m + n - 1;
        while (j >= 0) {
            ( i >= 0 && nums1[i] > nums2[j] ) ? nums1[length--] =nums1[i--] : nums1[length--] =nums2[j--];
        }
    }
};



int main()
{
	Solution testcase;
	
	//input array 1
	cout << "input the test case array1 size:" << endl;
	int testarraysize1;
	cin >> testarraysize1;

	cout << "input the test case array2 size:" << endl;
	int testarraysize2;
	cin >> testarraysize2;

	cout << "input the test case array1:" << endl;
	int testarray1[testarraysize1];
	for (int i = 0; i < testarraysize1; ++i)
	{
		cout << "please input the " << i+1 << " element:" << endl;
		cin >>testarray1[i];
	}
	//input array 2
	cout << "input the test case array2:" << endl;
	int testarray2[testarraysize2];
	for (int i = 0; i < testarraysize2; ++i)
	{
		cout << "please input the " << i+1 << " element:" << endl;
		cin >>testarray2[i];
	}

	
	//generate the vector
	vector <int> testvector1(testarray1,testarray1 + testarraysize1);
	vector <int> testvector2(testarray2,testarray2 + testarraysize2); 

	for (int i = 0; i < testarraysize2; ++i)
	{
		testvector1.push_back(0);
	}

	testcase.merge(testvector1, testarraysize1, testvector2, testarraysize2);

	for(int i=0;i<=testvector1.size()-1;i++)
		{
			cout << testvector1[i];
		}
		cout << endl;

}