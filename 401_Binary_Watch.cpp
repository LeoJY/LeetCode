//401. Binary Watch
//A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
//Each LED represents a zero or one, with the least significant bit on the right.
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	vector<string> result;
    	for (h = 0; h < 12; h ++){
    		for (m = 0; m < 59; m ++){
    			if (bitset<10>((h << 6)| m).count() = num){
    				result.push_back(to_string(h) + (m >= 10 ? ":" : ": 0") + to_string(m));
    			} 
    		}
    	}
    	return result;
    }
};
*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	vector<string> result;
    	vector<int> hour = {8, 4, 2, 1};
    	vector<int> minute = {32, 16, 8, 4, 2, 1};
    	for (int i = 0; i <= min(num, 4); ++i){
    		vector<int> hourList = generateDigit(hour, i);
    		vector<int> minuteList = generateDigit(minute, num - i);
    		for (auto i : hourList){
    			if (i >= 12) continue;
    			for (auto j : minuteList){
    				if (j >= 60) continue;
                    result.push_back(to_string(i) + (j >= 10 ? ":" : ":0") + to_string(j));
    			}
    		}
    	}
    	return result;
    }
private:
	vector<int> generateDigit(vector<int> & num, int count){
		vector<int> result;
		generateDigitHelper(num, count, 0, 0, result);
		return result;
	}
	void generateDigitHelper(vector<int> & num, int count, int pos, int sum, vector<int> & result){
		if (count == 0){
			result.push_back(sum);
			return;
		}
		if (pos + count > num.size()) return;
		for (int i = pos; i < num.size(); i ++){
			generateDigitHelper(num, count - 1, i + 1, sum + num[i], result);
		}
	}
};

int main(){
	Solution testCase;
	int testInt;
	cout << "please input the testInt" << endl;
	cin >> testInt;
	vector<string> testResult = testCase.readBinaryWatch(testInt);
	for (auto i : testResult) cout << i << endl;
	return 0;
}