//370. Range Addition
//Assume you have an array of length n initialized with all 0's and are given k update operations.
//Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
//Return the modified array after all k operations were executed.

//Hint:
//Thinking of using advanced data structures? You are thinking it too complicated.
//For each update operation, do you really need to update all elements between i and j?
//Update only the first and end element is sufficient.
//The optimal time complexity is O(k + n) and uses O(1) extra space.


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        for (auto i : updates){
        	result[i[0]] += i[2];
        	if (i[1] < length - 1) result[i[1] + 1] -= i[2];
        }
        for (int i = 1; i < length; i++){
        	result[i] += result[i - 1];
        }
        return result;
    }
};