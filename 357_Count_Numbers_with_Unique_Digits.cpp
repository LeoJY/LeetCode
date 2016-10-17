//357. Count Numbers with Unique Digits
//Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.

#include <iostream>
//#include <numeric>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	vector<int> numWithUnique(min(n, 10) + 1, 1);
    	for (int i = 1; i <= min(10 , n); ++i){
    		numWithUnique[i] = numWithUnique[i - 1] * ((i == 1) ? 9 : (11 - i));
    	}
    	return accumulate(numWithUnique.begin(), numWithUnique.end(), 0);
    }
};
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	vector<bool> used(10, false);
    	int count = 0;
    	for (int i = 0; i <= min(10, n); ++i)
    	{
    		count += helper(i, 0, used);
    	}
    	return count;
    }
private:
	int helper(int target, int index, vector<bool>& used){
		if (target == index) return 1;
		int countSub = 0;
		for (int i = (index? 0 : 1); i < 10; ++i)
		{
			if (!used[i]){
				used[i] = true;
				countSub += helper(target, index + 1, used);
				used[i] = false;
			}
		}
		return countSub;
	}
};


int main(){
	Solution testcase;
	int testnumber;
	cout << "please input the test number" << endl;
	cin >> testnumber;
	int testresult = testcase.countNumbersWithUniqueDigits(testnumber);
	cout << "the result is " << testresult << endl;
	return 0;
}