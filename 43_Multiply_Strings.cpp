//43. Multiply Strings
//Given two numbers represented as strings, return multiplication of the numbers as a string.
//Note:
//*The numbers can be arbitrarily large and are non-negative.
//*Converting the input string to integer is NOT allowed.
//*You should NOT use internal library such as BigInteger.

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	string multiply(string num1, string num2){
		string result(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1; i >= 0; --i){
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; --j){
				int temp = (result[i + j + 1] - '0') + carry + (num1[i] - '0') * (num2[j] - '0');
				result[i + j + 1] = temp % 10 + '0';
				carry = temp / 10;
			}
			result[i] += carry;
		}
		int startpos = result.find_first_not_of("0");
		if (startpos != string::npos) return result.substr(startpos);
		return "0";
	}
};

int main(){
	Solution testcase;
	string teststring1, teststring2;
	cout<< "please input the teststring 1:" << endl;
	getline(cin, teststring1);
	cout<< "please input the teststring 2:" << endl;
	getline(cin, teststring2);
	string testresult = testcase.multiply(teststring1, teststring2);
	cout << "the result is:" << endl;
	cout << teststring1 << " * " << teststring2 << " = " << testresult << endl;
	return 0;
}