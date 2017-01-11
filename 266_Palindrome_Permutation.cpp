//266. Palindrome Permutation
//Given a string, determine if a permutation of the string could form a palindrome.
//Hint:
//Consider the palindromes of odd vs even length. What difference do you notice?
//Count the frequency of each character.
//If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> mySet;
        for (char i : s) mySet.flip(i);
        return mySet.count() <= 1;
    }
};
