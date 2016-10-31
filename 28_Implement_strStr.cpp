//28. Implement strStr()
//Implement strStr().
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	int m = haystack.size(), n = needle.size();
    	if (!n) return 0;
    	vector<int> kmp = kmpProcess(needle);
    	for (int i = 0, j = 0; i < m;){
    		if (haystack[i] == needle[j]){
    			i++;
    			j++;
    		} 
    		if (j == n) return i - j;
    		if (i < m && haystack[i] != needle[j]){
    			if (j != 0) j = kmp[j - 1];
    			else i ++;
    		}
    	}
    	return -1;
    }
private:
	vector<int> kmpProcess(string needle){
		int n = needle.size();
		vector<int> result(n, 0);
		for (int i = 0, j = 1; j < n;){
			if (needle[i] == needle[j]) result[j ++] = ++i;
			else if (i != 0) i = result[i - 1];
			else result [j++] = 0;
		}
		return result;
	}
};

int main(){
	Solution testCase;
	cout << "please input the stringHaystack" << endl;
	string testStringHaystack;
	getline(cin, testStringHaystack);
	cout << "please input the stringNeedle" << endl;
	string testStringNeedle;
	getline(cin, testStringNeedle);
	int testResult = testCase.strStr(testStringHaystack, testStringNeedle);
	cout << "the result is " << testResult << endl;
	return 0;
}

