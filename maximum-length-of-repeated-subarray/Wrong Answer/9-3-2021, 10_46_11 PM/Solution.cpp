// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        int ml = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else if(nums1[i] == nums2[j])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ml = max(ml, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return ml;
    }
};