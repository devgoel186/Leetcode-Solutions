// https://leetcode.com/problems/candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        // sort(rating.begin(), rating.end());
        int n = ratings.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i - 1])
            {
                dp[i] = 1 + dp[i - 1];
            }
            else
            {
                if(dp[i - 1] != 1)
                    dp[i] = 1;
                else
                {
                    int j = i;
                    while(j >= 1 && dp[j] < dp[j - 1])
                    {
                        dp[j - 1]++;
                        j--;
                    }
                    dp[i] = 1;
                }
            }
        }
        
        int sum = 0;
        for(auto i : dp)
        {
            sum += i;
        }
        return sum;
    }
};