// https://leetcode.com/problems/number-of-visible-people-in-a-queue

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[n - 1] = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            int count = 0, currMax = 0;
            for(int j = i + 1; j < n; j++)    
            {
                if(heights[j] >= heights[i])
                {
                    count++;
                    break;
                }
                
                if(min(heights[i], heights[j]) > currMax)
                {
                    currMax = max(currMax, heights[j]);
                    count++;
                }
            }
            dp[i] = count;
        }
        
        return dp;
    }
};