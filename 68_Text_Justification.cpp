//68. Text Justification
//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//For the last line of text, it should be left justified and no extra space is inserted between words.
//Note: Each word is guaranteed not to exceed L in length.


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        for (int i = 0, k, l; i < words.size(); i += k){
        	for (k = 0, l = 0; i + k < words.size() && l + words[i + k].size() <= maxWidth - k; k++){
        		l += words[i + k].size();
        	}
        	string temp = words[i];
        	for (int j = 0; j < k - 1; j++){
        		if (i + k >= words.size()) temp += " ";
        		else temp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');
        		temp += words[i + j + 1];
        	}
        	temp += string(maxWidth - temp.size(), ' ');
        	result.push_back(temp);
        }
        return result;
    }
};