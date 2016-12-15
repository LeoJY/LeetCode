//4. Median of Two Sorted Arrays
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2) return findMedianSortedArrays(nums2, nums1);
        int i, j, low = 0, high = len1, num1, num2, half = (len1 + len2 + 1) >> 1;
        while(low <= high){
        	i = low + (high - low) / 2;
        	j = half - i;
        	if (i < len1 && j > 0 && nums2[j - 1] > nums1[i]) low = i + 1;
        	else if (i > 0 && j < len2 && nums1[i - 1] > nums2[j]) high = i - 1;
        	else break;
        }
        if (i == 0) num1 = nums2[j - 1];
        else if (j == 0) num1 = nums1[i - 1];
        else num1 = max(nums1[i - 1], nums2[j - 1]);
        if ((len1 + len2) & 1) return num1;
        if (i == len1) num2 = nums2[j];
        else if (j == len2) num2 = nums1[i];
        else num2 = min(nums1[i], nums2[j]);
        return (num1 + num2) / 2.0;
    }
};
