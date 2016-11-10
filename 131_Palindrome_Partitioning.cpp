//131. Palindrome Partitioning
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return all possible palindrome partitioning of s.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
    	vector<string> temp;
    	vector<vector<string>> result;
    	if (s.size() == 0) return result;
    	helper(s, 0, temp, result);
    	return result;
    }
private:
	void helper(string s, int start, vector<string> & temp, vector<vector<string>> & result){
		if(start == s.size()){
			result.push_back(temp);
			return;
		}
		for (int i = start + 1; i <= s.size(); i++){
			if (isPalindrome(s, start, i)){
				temp.push_back(s.substr(start, i - start));
				helper(s, i , temp, result);
				temp.pop_back();
			}
		}
	}
	bool isPalindrome(string s, int start, int end){
		int low = start, high = end - 1;
		while(low <= high){
			if (s[low ++] != s[high --]) return false;
		}
		return true;
	}
};

int main(){
	Solution testCase;
	string testString;
	cout << "please input the testString" << endl;
	cin >> testString;
	vector<vector<string>> testResult = testCase.partition(testString);
	for (auto i : testResult){
		for (auto j : i) {
			cout << j << '\t';
		}
		cout << endl;
	}
	return 0;
}
