//349. Intersection of Two Arrays
//Given two arrays, write a function to compute their intersection.
//Note:
//Each element in the result must be unique.
//The result can be in any order.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	unordered_set<int> unqNum;
    	vector<int> result;
    	for (auto i : nums1) unqNum.insert(i);
    	// or use unordered_set<int> unqNum(nums1.begin(), nums1.end());
    	for (auto i : nums2){
    		if (unqNum.find(i) != unqNum.end()){
    			result.push_back(i);
    			unqNum.erase(i);
    		}
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
	vector<int> testResult = testCase.intersection(testVector1, testVector2);
	for (auto i : testResult){
		cout << i << '\t';
	}
	cout << endl;
	return 0; 
}


