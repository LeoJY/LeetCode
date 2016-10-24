//347. Top K Frequent Elements
//Given a non-empty array of integers, return the k most frequent elements.
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	unordered_map<int, int> numCount;
    	vector<int> result;
    	for (auto i : nums) numCount[i]++;
    	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> countQueue;
    	for (auto i : numCount) {
    		countQueue.push(make_pair(i.second, i.first));
    		if (countQueue.size() > k) countQueue.pop();
    	}
    	while (countQueue.size()){
    		result.push_back(countQueue.top().second);
    		countQueue.pop();
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	vector<int> testVector;
	string temp;
	int number, testNum;
	cout << "please input the testVector, seperate with space, end with enter" << endl;
	getline(cin, temp);
	istringstream strcin(temp);
	while (strcin >> number){
		testVector.push_back(number);
	}
	cout << "please input the test integer" << endl;
	cin >> testNum;

	vector<int> testResult = testCase.topKFrequent(testVector, testNum);
	for (auto i : testResult){
		cout << i << '\t';
	}
	cout << endl;
	return 0; 
}