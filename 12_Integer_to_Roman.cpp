//12. Integer to Roman
//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	if (num <= 0) return "Invalid input";
        string result = "";
        vector<pair<int, string>> map = {{1000, "M"}, {900, "CM"},  {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},{50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},{5, "V"}, {4, "IV"}, {1, "I"}};
        while (num){
        	for (auto i : map){
        		if (i. first > num) continue;
        		int count = num / i.first;
        		for (int j = 0; j < count; ++j)
        		{
        			result += i.second;
        		}
        		num -= count * i.first;
        	}
        }
        return result;
    }
};

int main(){
	Solution testcase;
	int testnumber;
	cout << "please input the testnumber" << endl;
	cin >> testnumber;
	string testresult = testcase.intToRoman(testnumber);
	cout << "the result is :" << endl << testresult << endl;
	return 0;
}
