// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& A) {
        vector<int> dp(3);
        
        for (auto a : A)
        {
            for (auto i : vector<int>(dp))
            {
                int x = (i + a) % 3;
                dp[x] = max(dp[x], i + a);
            }
        }
        
        return dp[0];
    }
};