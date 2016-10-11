//9. Palindrome Number
//Determine whether an integer is a palindrome. Do this without extra space.

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0) return false;
    	int slow = x, fast = x, revlow = 0;
    	while (fast){
    		revlow = revlow * 10 + slow % 10;
    		slow /= 10;
    		fast /= 100;
    	}
    	return (slow == revlow || slow == revlow / 10);
    }
};

int main()
{
	Solution testcase;
	int testnumber;
	cout << "please input the testnumber" << endl;
	cin >> testnumber;
	bool testresult = testcase.isPalindrome(testnumber);
	if (testresult) cout << "the number is Palindrome" << endl;
	else cout << "the number is not Palindrome" << endl;
	return 0;
}