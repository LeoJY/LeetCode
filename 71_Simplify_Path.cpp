//71. Simplify Path
//Given an absolute path for a file (Unix-style), simplify it.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	istringstream cinstr(path);
    	string temp;
    	vector<string> tempfolder;
    	while(getline(cinstr, temp, '/')){
    		if (temp == "." || temp == "") continue;
    		else if (temp == ".."){
    			if (! tempfolder.empty()) tempfolder.pop_back();
    		}
    		else tempfolder.push_back(temp);
    	}
    	if (tempfolder.empty()) return "/";
    	else{
    		string result = "";
    		for (auto i : tempfolder) result += ("/" + i);
    		return result; 
    	}
    }
};


int main(){
	Solution testCase;
	string testString;
	cout << "please input the testString" << endl;
	getline(cin, testString);
	string testResult = testCase.simplifyPath(testString);
	cout << testResult << endl;
	return 0;
}
