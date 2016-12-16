//42. Trapping Rain Water
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxleft = 0, maxright = 0, water = 0;
        while (l <= r){
        	if (height[l] < height[r]){
        		if (height[l] > maxleft) maxleft = height[l++];
        		else water += maxleft - height[l++];
        	}
        	else{
        		if (height[r] > maxright) maxright = height[r--];
        		else water += maxright - height[r--];
        	}
        }
        return water;
    }
};
