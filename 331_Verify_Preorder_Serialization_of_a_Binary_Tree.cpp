//331. Verify Preorder Serialization of a Binary Tree
//One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
		int nullp = 0, nodep = 0;
		istringstream cinstr(preorder);
		string temp;
		vector<string> testVec;
		while(getline(cinstr, temp, ',')) testVec.push_back(temp);
		for (int i = 0; i < testVec.size(); ++i){
			if (testVec[i] == "#") nullp ++;
			else nodep ++;
			if (nodep + 1 == nullp && i != testVec.size() - 1) return false; 
		}
		return nodep + 1 == nullp;
    }
};


int main(){
	Solution testCase;
	cout << "please input the testString, seperate with \'\', end with enter" << endl;
	string testString;
	cin >> testString;
	bool testResult = testCase.isValidSerialization(testString);
	cout << "the result is " << (testResult ? "Ture" : "False") << endl;
	return 0;
}