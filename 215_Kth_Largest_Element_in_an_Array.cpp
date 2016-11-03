//215. Kth Largest Element in an Array
//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ array's length.
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	priority_queue<int, vector<int>, greater<int>> q;
    	for (int i : nums){
    		q.push(i);
    		if (q.size() > k) q.pop();
    	}
    	return q.top();
    }
};

int main(){
	Solution testCase;
	string testStr;
	int testInteger, temp;
	vector<int> testVector;
	cout << "please input the target integer" << endl;
	cin >> testInteger;
	cout << "please input the testStr" << endl;
	cin.ignore(); //clear the cin flow!!!
	getline(cin, testStr);
	istringstream cinstr(testStr);
	while(cinstr >> temp){
		testVector.push_back(temp);
	}
	int testResult = testCase.findKthLargest(testVector, testInteger);
	cout << "the result is " << testResult << endl;
	return 0;
}
