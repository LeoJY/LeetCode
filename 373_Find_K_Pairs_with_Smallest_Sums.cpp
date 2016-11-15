//373. Find K Pairs with Smallest Sums
//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//Define a pair (u,v) which consists of one element from the first array and one element from the second array.
//Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	vector<pair<int, int>> result;
    	if(nums1.empty() || nums2.empty() || k<= 0) return result;
    	auto compare = [&nums1, &nums2](pair<int, int> a, pair<int, int> b){
    		return (nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]);
    	};
    	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> myQueue(compare);
    	myQueue.push(make_pair(0, 0));
    	while(k -- > 0 && myQueue.size()){
    		auto minPair = myQueue.top();
    		myQueue.pop();
    		result.push_back(make_pair(nums1[minPair.first], nums2[minPair.second]));
    		if (minPair.first + 1 < nums1.size()) myQueue.push(make_pair(minPair.first + 1, minPair.second));
    		if (minPair.first == 0 && minPair.second + 1 < nums2.size()) myQueue.push(make_pair(minPair.first, minPair.second + 1));
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	int testInt, temp;
	string testString1, testString2;
	vector<int> testVec1, testVec2;
	cout << "please input the testInt" << endl;
	cin >> testInt;
	cin.ignore();
	cout << "please input the first nums, seperate with space, end with space" << endl;
	getline(cin, testString1);
	cout << "please input the second nums, seperate with space, end with space" << endl;
	getline(cin, testString2);
	istringstream cinstr1(testString1);
	istringstream cinstr2(testString2);
	while (cinstr1 >> temp){
		testVec1.push_back(temp);
	}
	while (cinstr2 >> temp){
		testVec2.push_back(temp);
	}
	vector<pair<int, int>> testResult = testCase.kSmallestPairs(testVec1, testVec2, testInt);
	for (auto i : testResult) cout << "[" << i.first << ", " << i.second << "]" << endl;
	return 0;
}