//93. Restore IP Addresses
//Given a string containing only digits, restore it by returning all possible valid IP address combinations.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	vector<string> result;
    	vector<string> temp;
    	helper(s, result, temp, s.size());
    	return result;
    }
private:
	void helper(string s, vector<string>& result, vector<string>& temp, int len){
		if (temp.size() == 4 && len == 0){
			string tmp = temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3];
			result.push_back(tmp);
			return;
		}
		else if ((temp.size() == 4 && len != 0) || (temp.size() != 4 && len == 0)) return;
		else{
			for (int i = 1; i <= 3 && i <= len; ++i){
				string tmp = s.substr(s.size() - len, i);
				int tmpval = stoi(tmp);
				if (tmpval >= 0 && tmpval <= 255 &&(i == 1 || tmp[0] != '0')){
					temp.push_back(tmp);
					helper(s, result, temp, len - i);
					temp.pop_back();
				}
			}
		}
	}
};

int main(){
	Solution testCase;
	string testString;
	cout << "please input the testString" << endl;
	getline(cin, testString);
	vector<string> testResult = testCase.restoreIpAddresses(testString);
	for(auto i : testResult) cout << i << endl;
	return 0;
}
