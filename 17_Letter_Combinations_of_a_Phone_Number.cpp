//17. Letter Combinations of a Phone Number
//Given a digit string, return all possible letter combinations that the number could represent.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int n = digits.size();
        if (n < 1)  return result;
        const string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");
        for (int i = 0; i < n; ++i)
        {
        	vector<string> temp;
        	string chars = map[digits[i] - '0'];
        	for (int j = 0; j < chars.size(); ++j){
        		for (int k = 0; k < result.size(); ++k)
        		{
        			temp.push_back(result[k] + chars[j]);
        		}
        	}
        	result = temp;
        }
        return result;
    }
};

int main()
{
	Solution testcase;
	//input the array
	string teststring;
	cout << "input the string (EOL = $)" << endl;
	getline(cin, teststring, '$');

	//call the function
	vector<string> testresult = testcase.letterCombinations(teststring);
	
 	cout << "the result is:"  << endl;
 	for (int i = 0; i < testresult.size(); ++i)
 	{
 		cout << testresult[i] << endl;
 	}

	return 0;
}