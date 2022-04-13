// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area = 0;
        
        while(l < r)
        {
            int h = min(height[l], height[r]);
            int x = r - l;
            area = max(area, h * x);
            
            if(h == height[l])
                l++;
            else
                r--;
        }
        
        return area;
    }
};