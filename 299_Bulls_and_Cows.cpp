//299. Bulls and Cows
//You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.
//Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

#include <iostream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
    	int numCount[10] = {0};
    	int bull = 0, cow = 0;
    	if (secret.size() != guess.size()) return "Invalid Guess";
    	for (int i = 0; i < secret.size(); i++){
    		if (secret[i] == guess[i]) bull++;
    		else{
    			if (numCount[secret[i] - '0']++ < 0) cow ++;
    			if (numCount[guess[i] - '0']-- > 0) cow ++;
    		}
    	}
    	return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

int main(){
	Solution testCase;
	string testSecret, testGuess;
	cout << "please input the testSecret" << endl;
	getline(cin, testSecret);	
	cout << "please input the testGuess" << endl;
	getline(cin, testGuess);
	string testResult = testCase.getHint(testSecret, testGuess);
	cout << "the result is " << testResult << endl;
	return 0; 
}