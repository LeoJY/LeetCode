//187. Repeated DNA Sequences
//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	unordered_map <int, int> stringCount;
    	int n = s.size();
    	vector<string> result;
    	int i = 0, temp = 0;
    	for (i = 0; i < 9; ++i){
			temp = temp << 3 | (7 & s[i]);    		
    	}
    	while (i < n){
    		if (stringCount[temp = (temp << 3 & 0x3FFFFFFF) | (7 & s[i++])]++ == 1){
    			result.push_back(s.substr(i-10, 10));
    		}
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	string testString;
	cout << "please input the testString" << endl;
	getline(cin, testString);
	vector<string> testResult = testCase.findRepeatedDnaSequences(testString);
	cout << "the result is " << endl;
	for (int i = 0; i < testResult.size(); ++i)
	{
		cout<< testResult[i] << endl;
	}
	return 0;
}