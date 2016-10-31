//345. Reverse Vowels of a String
//Write a function that takes a string as input and reverse only the vowels of a string.
//Note:
//The vowels does not include the letter "y".

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
    	string vowel = "aeiouAEIOU";
    	int j = s.size() - 1;
    	int i = 0;
    	while(i < j){
    		while (vowel.find(s[i]) == string::npos && i < j) i++;
    		while (vowel.find(s[j]) == string::npos && i < j) j--;
    		swap(s[i++], s[j--]);
    	}
    	return s;
    }
};

int main(){
	Solution testCase;
	cout << "please input the string" << endl;
	string testString;
	getline(cin, testString);
	string testResult = testCase.reverseVowels(testString);
	cout << "the result is " << testResult << endl;
	return 0;
}