//402. Remove K Digits
//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//Note:
//The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
    	int n = num.size();
    	if (k >= n) return "0";
    	string result;
    	for (int i = 0; i < n ; i ++){
    		while(k > 0 && !result.empty() && result.back() > num[i]){
    			result.pop_back();
    			k --;
    		}
    		result.push_back(num[i]);
    	}
    	while(k){
    		k --;
    		result.pop_back();
    	}
    	while (result[0] == '0') result.erase(0,1);
    	return result.empty() ? "0" : result;
    }
};

int main(){
	Solution testCase;
	int testInt;
	string testString;
	cout << "please input the testInt" << endl;
	cin >> testInt;
	cin.ignore();
	cout << "please input the testString" << endl;
	getline(cin, testString);
	string testResult = testCase.removeKdigits(testString, testInt);
	cout << "the testResult is " << endl << testResult << endl;
	return 0;
}
