//162. Find Peak Element
//A peak element is an element that is greater than its neighbors.
//Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//You may imagine that num[-1] = num[n] = -∞.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
    	int n = num.size();
    	int low = 0, high = n - 1;
    	while (low < high){
    		int mid = low + (high - low) / 2;
    		if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) return mid;
    		if (num[mid] > num[mid + 1]) high = mid - 1;
    		else low = mid + 1;
    	}
    	return low;
    }
 };

 int main(){
	Solution testcase;
	vector<int> testvector;
	int input;
	cout << "please input the test vector(EOF = -9999): " << endl;
	while(cin >> input && input != -9999){
		testvector.push_back(input);
	}
	int testresult = testcase.findPeakElement(testvector);
	cout << "the result is: " << testresult << endl;
	return 0;
}


