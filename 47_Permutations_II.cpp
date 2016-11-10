//47. Permutations II
//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
    	sort(num.begin(), num.end());
    	vector<vector<int>> result;
    	helper(num, 0, result);
    	return result;
    }
private:
	void helper(vector<int> num, int i, vector<vector<int>> &result){
		int n = num.size();
		if (i == n - 1){
			result.push_back(num);
			return;
		}
		for(int j = i; j < n; j ++){
            if (i != j && num[i] == num[j]) continue;
			swap(num[i], num[j]);
			helper(num, i + 1, result);
		}
	}
};

int main(){
	Solution testCase;
	string testString;
	int temp;
	vector<int> testVector;
	cout << "please input the numbers, seperate with space, end with enter" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while(cinstr >> temp){
		testVector.push_back(temp);
	}
	cout << "the result is:" << endl;
	vector<vector<int>> testResult = testCase.permuteUnique(testVector);
	for (auto i : testResult){
		for (auto j : i) cout << j << " ";
		cout <<  endl;
	}
	return 0;
}




