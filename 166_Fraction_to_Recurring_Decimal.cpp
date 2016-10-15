//166. Fraction to Recurring Decimal
//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
	string fractionToDecimal(int numerator, int denominator){
		if (numerator == 0) return "0";
		if (denominator == 0) return "Invalid Input";
		string result = "";
		if (numerator < 0 ^ denominator < 0) result += '-';
		long int n = labs(numerator);
		long int d = labs(denominator);
		result += to_string(n / d);
		if ( n % d == 0) return result ;
		result += '.';
		unordered_map <int, int> remainder;
		for (long int i = n % d; i; i %= d)
		{
			if (remainder.count(i) > 0){
				result.insert(remainder[i], 1, '(');
				result += ')';
				break;
			}
			remainder[i] = result.size();
			i *= 10;
			result += to_string(i / d);
		}
		return result;
	}
};

int main(){
	Solution testcase;
	cout << "please input the numerator and the denominator" << endl;
	int testNumerator, testDenominator;
	cin >> testNumerator >> testDenominator;
	string testresult = testcase.fractionToDecimal(testNumerator, testDenominator);
	cout << testNumerator << " / " << testDenominator << " = " << testresult << endl;
	return 0;
}
