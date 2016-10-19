//49. Group Anagrams
//Given an array of strings, group anagrams together.
//Note: All inputs will be in lower-case.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        unordered_map<int, int> stringMap;
        vector<vector<string>> result;
        for (string i : strs){
        	int key = 1;
        	for (char j : i){
        		key *= prime[j - 'a'];
        	}
        	if (stringMap.find(key) == stringMap.end()){
        		vector<string> temp = {i};
        		stringMap[key] = result.size();
        		result.push_back(temp);
        	}
        	else result[stringMap[key]].push_back(i);
        }
        return result;
    }
};

int main(){
	Solution testCase;
	string temp;
	vector<string> testVector;
	cout << "please input the testVector (EOF = 0000)" << endl;
	while( cin >> temp && temp != "0000"){
		testVector.push_back(temp);
	}
	vector<vector<string>> testResult = testCase.groupAnagrams(testVector);
	for (int i = 0; i < testResult.size(); ++i)
	{
		for (int j = 0; j < testResult[i].size(); ++j)
		{
			cout << testResult[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}