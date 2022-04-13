// https://leetcode.com/problems/candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        // sort(rating.begin(), rating.end());
        int n = ratings.size(), sum = 0;
        vector<int> dp(n, 1);
        dp[0] = 1;
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i - 1])
                dp[i] = 1 + dp[i - 1];
        
        for(int i = n - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1] && dp[i] <= dp[i + 1])
                dp[i] = dp[i + 1] + 1;
        
        for(auto i : dp)
            sum += i;
        return sum;
    }
};