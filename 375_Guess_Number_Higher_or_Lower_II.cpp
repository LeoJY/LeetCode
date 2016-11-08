//375. Guess Number Higher or Lower II
//We are playing the Guess Game. The game is as follows:
//I pick a number from 1 to n. You have to guess which number I picked.
//Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
    	vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    	return helper(table, 1, n);
    }
private:
	int helper(vector<vector<int>>&table, int s, int e){
		if (e <= s) return 0;
		if (table[s][e] != 0) return table[s][e];
		int result = INT_MAX;
		for (int i = s; i <= e; i++){
			int temp = i + max(helper(table, s, i - 1), helper(table, i + 1, e));
			result = min(result, temp);
		}
		table[s][e] = result;
		return result;
	}
};

int main(){
	Solution testcase;
	int testInt;
	cout << "please input a test number" << endl;
	cin >> testInt;
	int testresult = testcase.getMoneyAmount(testInt);
	cout << "the result is " << testresult << endl;
}