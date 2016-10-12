//60. Permutation Sequence
//The set [1,2,3,…,n] contains a total of n! unique permutations.
//By listing and labeling all of the permutations in order,
//We get the following sequence 
//Given n and k, return the kth permutation sequence.

#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	string result(n , '0');
    	int factor = 1;
    	for (int i = 1; i <= n; ++i)
    	{
    		factor *= i;
    		result[i - 1] += i;
    	}
    	k --;
    	for (int i = 0; i < n; ++i)
    	{
    		factor /= (n - i);
    		int j = i + k / factor;
    		char temp = result[j];
    		for (; i < j; j--)
    		{
    			result[j] = result[j - 1];
    		}
    		result[i] = temp;
    		k %= factor;
    	}
    	return result;
    }
};

int main(){
	Solution testcase;
	int testn, testk;
	cout << "please input the number n and k" << endl;
	cin >> testn >> testk;
	string testresult = testcase.getPermutation(testn, testk);
	cout << "the result is" << endl << testresult << endl;
	return 0;
}