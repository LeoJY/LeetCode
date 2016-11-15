//179. Largest Number
//Given a list of non negative integers, arrange them such that they form the largest number.
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//Note: The result may be very large, so you need to return a string instead of an integer.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	vector<string> temp;
    	for (auto i : nums) temp.push_back(to_string(i));
    	auto compare = [](string& s1, string& s2){
    		return s1 + s2 > s2 + s1;
    	};
    	sort(temp.begin(), temp.end(), compare);
    	string result = "";
    	for (auto i : temp) result += i;
    	while (result[0] == '0') result.erase(0, 1);
    	return result.empty() ? "0" : result;
    }
};

int main(){
	Solution testCase;
	int temp;
	string testString;
	vector<int> testVec;
	cout << "please input the test numbers, seperate with space, end with enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while (cinstr >> temp){
		testVec.push_back(temp);
	}
	string testResult = testCase.largestNumber(testVec);
	cout << "the result is " << endl << testResult << endl;
	return 0;
}
