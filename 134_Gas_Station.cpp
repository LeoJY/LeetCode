//134. Gas Station
//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//Note:
//The solution is guaranteed to be unique.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	if (gas.empty() || gas.size() != cost.size()) return  -1;
    	int start = gas.size() - 1, end = 0;
    	int sum = gas[start] - cost[start];
    	while (start > end){
    		if (sum >= 0){
    			sum += gas[end] - cost[end];
    			end ++;
    		}
    		else{
    			start --;
    			sum += gas[start] - cost[start];
    		}
    	}
    	return sum >= 0 ? start : -1;
    }
};

int main(){
	Solution testCase;
	int temp;
	string testString1, testString2;
	vector<int> testVec1, testVec2;
	cout << "please input the first nums(gas), seperate with space, end with space" << endl;
	getline(cin, testString1);
	cout << "please input the second nums(cost), seperate with space, end with space" << endl;
	getline(cin, testString2);
	istringstream cinstr1(testString1);
	istringstream cinstr2(testString2);
	while (cinstr1 >> temp){
		testVec1.push_back(temp);
	}
	while (cinstr2 >> temp){
		testVec2.push_back(temp);
	}
	int testResult = testCase.canCompleteCircuit(testVec1, testVec2);
	cout << "the result is " << endl << testResult << endl;
	return 0;
}
