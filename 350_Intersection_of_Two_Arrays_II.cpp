//350. Intersection of Two Arrays II
//Given two arrays, write a function to compute their intersection.
//Follow up:
//What if the given array is already sorted? How would you optimize your algorithm?
//What if nums1's size is small compared to nums2's size? Which algorithm is better?
//What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
    	unordered_map<int, int> numCount;
    	vector<int> result;
    	for (auto i : nums1) numCount[i]++;
    	for (auto i : nums2){
    		if (numCount[i]-- > 0) result.push_back(i);
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	vector<int> testVector1, testVector2;
	string temp, temp1;
	int number, testNum;
	cout << "please input the testVector1, seperate with space, end with enter" << endl;
	getline(cin, temp);
	istringstream strcin(temp);
	while (strcin >> number){
		testVector1.push_back(number);
	}
	
	cout << "please input the testVector2, seperate with space, end with enter" << endl;
	getline(cin, temp1);
	istringstream strcin1(temp1);
	while (strcin1 >> number){
		testVector2.push_back(number);
	}
	vector<int> testResult = testCase.intersect(testVector1, testVector2);
	for (auto i : testResult){
		cout << i << '\t';
	}
	cout << endl;
	return 0; 
}
