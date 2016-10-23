//274. H-Index
//Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
//According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
//For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
//Note: If there are several possible values for h, the maximum one is taken as the h-index.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int n = citations.size();
    	vector<int> citationCount(n + 1, 0);
    	for (auto i : citations){
    		if (i >= n) citationCount[n]++;
    		else citationCount[i]++;
    	}
    	int temp = 0;
    	for (int i = n; i >= 0;i--){
    		temp += citationCount[i];
    		if (temp >= i) return i;
    	}
    	return 0;
    }
};

int main(){
	Solution testCase;
	vector<int> testVector;
	cout << "please input the testVector (EOF = -9999)" << endl;
	int inputNum;
	while (cin >> inputNum && inputNum != -9999){
		testVector.push_back(inputNum);
	}
	int testResult = testCase.hIndex(testVector);
	cout << "the result is " << testResult << endl;
	return 0;
}