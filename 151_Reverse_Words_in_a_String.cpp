//151. Reverse Words in a String
//Given an input string, reverse the string word by word.
/*
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    void reverseword(string &s, int i, int j){
        while(i < j){
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
public:
    void reverseWords(string &s) {
    	int i = 0, j = 0, low;
    	int newlen, len = s.size();
    	int word = 0;
    	while(1){
    		while(i < len && s[i] == ' ') i++;
    		if (i == len) break;
    		if (word) s[j ++] = ' ';
    		int low = j;
    		while (s[i] != ' ' && i < len) s[j++] = s[i++];
    		reverseword(s, low, j - 1);
    		word ++;
    	}
    	s.resize(j);
    	reverseword(s, 0, j - 1);
    }
};

int main(){
	Solution testCase;
	string testString;
	cout << "please input the testString" << endl;
	getline(cin, testString);
	testCase.reverseWords(testString);
	cout << testString << endl;
	return 0;
}
