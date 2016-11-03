//241. Different Ways to Add Parentheses
//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	vector<int> output;
    	for (int i = 0; i < input.size(); ++i){
    		char c = input[i];
    		if (ispunct(c)){
    			for (auto a : diffWaysToCompute(input.substr(0, i))){
    				for (auto b : diffWaysToCompute(input.substr(i + 1))){
    					output.push_back(c == '+' ? a + b : (c == '-' ? a - b : a * b));
    				}
    			}
    		}
    	}
    	return (output.empty()? vector<int>{stoi(input)} : output);
    }
};

int main(){
	Solution testCase;
	cout << "please input the teststring" << endl;
	string teststring;
	cin >> teststring;
	vector<int> testResult = testCase.diffWaysToCompute(teststring);
	for (auto i : testResult) cout << i << endl;
	return 0;
}