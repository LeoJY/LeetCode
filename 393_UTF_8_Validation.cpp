//393. UTF-8 Validation
//A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
//For 1-byte character, the first bit is a 0, followed by its unicode code.
//For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
//Given an array of integers representing the data, return whether it is a valid utf-8 encoding.
//Note:
//The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto i : data){
        	if (count == 0){
        		if ((i >> 3) == 0b11110) count = 3;
        		else if ((i >> 4) == 0b1110) count = 2;
        		else if ((i >> 5) == 0b110) count = 1;
        		else if ((i >> 7 == 0b1)) return false;
        	}
        	else{
        		if ((i >> 6) != 0b10) return false;
        		count --;
        	}
        }
        return count == 0;
    }
};

int main(){
	Solution testCase;
	int temp;
	vector<int> testVec;
	string testString;
	cout << "please input the test numbers" << endl;
	getline(cin, testString);
	istringstream cinstr(testString);
	while (cinstr >> temp) testVec.push_back(temp);
	bool testResult = testCase.validUtf8(testVec);
	cout << "the result is " << (testResult ? "True" : "False" )<< endl;
	return 0;
}
