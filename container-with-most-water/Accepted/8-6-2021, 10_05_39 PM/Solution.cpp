// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int area = 0;
        while(l < r)
        {
            int height = min(heights[l], heights[r]);
            area = max(area, height * (r - l));
            if(height == heights[l])
                l++;
            else
                r--;
        }
        return area;
    }
};