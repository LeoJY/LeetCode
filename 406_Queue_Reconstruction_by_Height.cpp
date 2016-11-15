//406. Queue Reconstruction by Height
//Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//Note:
//The number of people is less than 1,100.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    	auto compare = [](pair<int, int> a, pair<int, int> b){
    		return a.first > b.first || (a.first == b.first && a.second < b.second);
    	};
    	sort(people.begin(), people.end(),compare);
    	vector<pair<int, int>> result;
    	for (auto i : people){
    		result.insert(result.begin() + i.second, i);
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	int temp1, temp2;
	string testString1, testString2;
	vector<pair<int, int>> testVec;
	cout << "please input the height, seperate with space, end with space" << endl;
	getline(cin, testString1);
	cout << "please input the rank, seperate with space, end with space" << endl;
	getline(cin, testString2);
	istringstream cinstr1(testString1);
	istringstream cinstr2(testString2);
	while (cinstr1 >> temp1 && cinstr2 >> temp2){
		testVec.push_back(make_pair(temp1, temp2));
	}
	vector<pair<int, int>> testResult = testCase.reconstructQueue(testVec);
	for (auto i : testResult) cout << "[" << i.first << ", " << i.second << "]" << endl;
	return 0;
}


