//67. Add Binary
//Given two binary strings, return their sum (also a binary string).

#include <iostream>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b){
    	string result = "";
    	int carry = 0, n = a.size() - 1, m = b.size() - 1;
    	while (n >= 0 || m >= 0 || carry == 1){
    		carry += n>=0 ? a[n--] - '0' : 0;
    		carry += m>=0 ? b[m--] - '0' : 0;
    		char temp = carry % 2 + '0';
    		result = temp + result;
    		carry /= 2;
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	string a, b;
	cout << "please input string a" << endl;
	cin >> a;
	cout << "please input string b" << endl;
	cin >> b;
	string testresult = testcase.addBinary(a, b);
	cout << a << " + " << b << " = " << testresult << endl;
	return 0;
}