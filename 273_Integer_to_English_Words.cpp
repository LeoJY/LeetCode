//273. Integer to English Words
//Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.
//Hint:
//Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
//Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
//There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)


class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        else{
        	string result = intToString(num);
        	return result.substr(1);
        }
    }
private:
	vector<string> underTwenty = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	vector<string> tensDigit = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	string intToString(int n){
		if (n >= 1000000000) return intToString(n / 1000000000) + " Billion" + intToString(n % 1000000000);
		else if (n >= 1000000) return intToString(n / 1000000) + " Million" + intToString(n % 1000000);
		else if (n >= 1000) return intToString(n / 1000) + " Thousand" + intToString(n % 1000);
		else if (n >= 100) return intToString(n / 100) + " Hundred" + intToString(n % 100);
		else if (n >= 20) return " " + tensDigit[n / 10]  + intToString(n % 10);
		else if (n >= 1) return " " + underTwenty[n];
		else return "";
	}
};