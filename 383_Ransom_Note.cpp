//383. Ransom Note
//Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
//Each letter in the magazine string can only be used once in your ransom note.
//Note:
//You may assume that both strings contain only lowercase letters.
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	unordered_map<char, int> charNum;
    	for (auto i : magazine) charNum[i]++;
    	for (auto i : ransomNote){
    		charNum[i]--;
    		if (charNum[i] < 0) return false;
    	}
    	return true;
    }
};

int main(){
	Solution testCase;
	string testString1, testString2;
	cout << "please input the ransomNote" << endl;
	getline(cin, testString1);
	cout << "please input the magazine" << endl;
	getline(cin, testString2);
	bool testResult = testCase.canConstruct(testString1, testString2);
	cout << (testResult ? "Yes" : "No") << endl;
	return 0;
}