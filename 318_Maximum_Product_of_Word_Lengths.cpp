//318. Maximum Product of Word Lengths
//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
    	int result = 0;
    	unordered_map<int, int> map;
    	for (auto i : words){
    		int mask = 0;
    		for (auto j : i) mask |= (1 << (j - 'a'));
    		map[mask] = max(map[mask], (int)i.size());
    		for (auto k : map){
    		    if((k.first & mask) == 0) result = max(result, map[mask] * k.second);
    		}
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	string testString;
	string temp;
	vector<string> testVec;
	cout << "please input the words, seperate with space, end with enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while (cinstr >> temp) testVec.push_back(temp);
	int testResult = testCase.maxProduct(testVec);
	cout << "the result is " << testResult << endl;
	return 0;
}