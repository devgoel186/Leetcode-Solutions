// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxWater = 0;
        
        while(i < j)
        {
            int dist = j - i;
            maxWater = max(maxWater, dist * min(height[i], height[j]));
            
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        
        return maxWater;
    }
};