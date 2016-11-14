//394. Decode String
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
//Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
    	int n = 0;
    	return decodeHelper(s, n);
    }
private:
	string decodeHelper(string s, int& index){
		string result = "";
		while(index < s.size() && s[index] != ']'){
			if (!isdigit(s[index])) result += s[index++];
			else{
				int n = 0;
				while(isdigit(s[index])) n = n * 10 + s[index++] - '0';
				index++; //skip '['
				string temp = decodeHelper(s, index);
				index++;
				while(n -- > 0) result += temp;
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
	string testResult = testCase.decodeString(testString);
	cout << "the result is " << endl << testResult << endl;
	return 0;
}
