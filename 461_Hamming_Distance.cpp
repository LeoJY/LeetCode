//461. Hamming Distance
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//Given two integers x and y, calculate the Hamming distance.
//Note:
//0 ≤ x, y < 2^31.


class Solution {
public:
    int hammingDistance(int x, int y) {
       return bitset<32>(x^y).count();
    }
};