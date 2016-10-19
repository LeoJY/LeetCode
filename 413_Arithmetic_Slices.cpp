//413. Arithmetic Slices
//A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
//A slice (P, Q) of array A is called arithmetic if the sequence:
//A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
//The function should return the number of arithmetic slices in the array A.

#include <iostream>
#include <vector>

using namespace std;

class Solution {    
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	if (A.size() < 3) return 0;
    	vector<int> dpNum(A.size(),0);
    	int result = 0;
    	for (int i = 2; i < A.size(); ++i)
    	{
    		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) dpNum[i] = dpNum[i - 1] + 1;
    		result +=dpNum[i];
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	int temp;
	vector<int> testVector;
	cout << "please input the testVector (EOF=-9999)" << endl;
	while(cin >> temp && temp != -9999){
		testVector.push_back(temp);
	}
	int testResult = testCase.numberOfArithmeticSlices(testVector);
	cout << "the result is: " << testResult << endl;
	return 0;
}