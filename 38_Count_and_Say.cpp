//38. Count and Say
//Given an integer n, generate the nth sequence.
//Note: The sequence of integers will be represented as a string.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	if (n == 0) return "";
    	string result = "1";
    	while(--n){
    		string cur = "";
    		for (int i = 0; i < result.size(); i++){
    			int count = 1;
    			while (i < result.size() && result[i] == result[i + 1]){
    				count ++;
    				i++;
    			}
    			cur += to_string(count) + result[i];
    		}
    		result = cur;
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	int testInteger;
	cout << "please input the testinteger" << endl;
	cin >> testInteger;
	string testResult = testCase.countAndSay(testInteger);
	cout << testResult << endl;
	return 0;
}
