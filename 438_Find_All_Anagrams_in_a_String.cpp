//438. Find All Anagrams in a String
//Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//The order of output does not matter.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> charCount(26,0);
        if(p.size() > s.size()) return result;
        for (auto i : p) charCount[i - 'a'] ++;
        for (int i = 0; i < p.size(); i ++) charCount[s[i] - 'a'] --;
        if (allZero(charCount)) result.push_back(0);
        for (int i = p.size(); i < s.size(); ++i)
        {
            charCount[s[i] - 'a'] --;
            charCount[s[i - p.size()] - 'a'] ++;
            if (allZero(charCount)) result.push_back(i - p.size() + 1); 
        }
        return result;
    }
private:
    bool allZero(vector<int> &s){
        for (auto i : s) {
            if (i) return false;
        }
    return true;
    }
};

int main(){
    Solution testCase;
    string testString1, testString2;
    cout << "please input the first string" << endl;
    getline(cin, testString1);
    cout << "please input the second string" << endl;
    getline(cin, testString2);
    vector<int> testResult = testCase.findAnagrams(testString1, testString2);
    for (auto i : testResult) cout << i << '\t';
    cout << endl;
    return 0;
}
