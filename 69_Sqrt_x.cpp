//69. Sqrt(x)
//Implement int sqrt(int x).
//Compute and return the square root of x.

#include <iostream>

using namespace std;
/*
class Solution {
public:
    int mySqrt(int x) {
    	long int r = x;
    	while (r * r > x){
    		r = (r + x / r) /2;
    	}
    	return r;
    }
};
*/

class Solution {
public:
    int mySqrt(int x) {
    	if (x == 0) return 0;
    	int low = 1, high = x;
    	while (low <= high){
    		int mid = low + (high - low) / 2;
    		int temp = x / mid;
    		if (temp == mid) return mid;
    		else if (temp < mid) high = mid - 1;
    		else low = mid + 1;
    	}
    	return high;
    }
};

int main()
{
	Solution testcase;
	int testnumber;
	cout << "please input a number" << endl;
	cin >> testnumber;
	int testresult = testcase.mySqrt(testnumber);
	cout << "the result is: " << testresult << endl;
	return 0;
}