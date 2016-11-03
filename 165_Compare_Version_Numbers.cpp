//165. Compare Version Numbers
//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int i = 0, j = 0, res1 = 0, res2 = 0;
    	int n1 = version1.size(), n2 = version2.size();
    	while(i < n1 || j < n2){
    		while (i < n1 && version1[i] != '.') res1 = res1 * 10 + (version1[i ++] - '0');
    		while (j < n2 && version2[j] != '.') res2 = res2 * 10 + (version2[j ++] - '0');
    		if (res1 > res2) return 1;
    		else if (res1 < res2) return -1;
    		res1 = 0;
    		res2 = 0;
    		i ++;
    		j++;
    	}
    	return 0;
    }
};

int main(){
	Solution testCase;
	string testString1, testString2;
	cout << "please input the first version" << endl;
	cin >> testString1;
	cout << "please input the second version" << endl;
	cin >> testString2;
	int testResult = testCase.compareVersion(testString1, testString2);
	cout << "the result is " << testResult << endl;
	return 0;
}