//275. H-Index II
//Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
//Hint:
//Expected runtime complexity is in O(log n) and the input is sorted.
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int n = citations.size();
    	int low = 0, high = n - 1;
    	while (low <= high){
    		int mid = low + (high - low) / 2;
    		if (citations[mid] == n -mid) return citations[mid];
    		else if (citations[mid] > n - mid) high = mid - 1;
    		else low = mid + 1;
    	}
    	return (n - high -1);
    }
};

int main(){
	Solution testcase;
	string testString;
	vector<int> testVec;
	cout << "please input the test vector, seperate by space, end by enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	int temp;
	while (cinstr >> temp){
		testVec.push_back(temp);
	}
	int testResult = testcase.hIndex(testVec);
	cout << "the result is " << testResult << endl;
	return 0;
}
