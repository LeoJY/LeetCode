//89. Gray Code
//The gray code is a binary numeral system where two successive values differ in only one bit.
//Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//Note:
//For a given n, a gray code sequence is not uniquely defined.
//For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> result (1, 0);
    	for (int i = 0; i < n; i++){
    		for (int j = result.size() - 1; j >=0; j--){
    			result.push_back(result[j] + (1 << i));
    		}
    	}
    	return result;
    }
};

int main(){
	Solution testCase;
	int testInt;
	cout << "please input the testInt" << endl;
	cin >> testInt;
	vector<int> testResult = testCase.grayCode(testInt);
	for (auto i : testResult){
		cout << i << endl;
	}
	return 0;
}

