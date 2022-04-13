// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(), 0);
        if(s[0] - '0' == 0)
            return 0;
        
        dp[0] = 1;
        int dl = ((s[0] - '0') * 10) + (s[1] - '0');
        if(dl >= 10 && dl <= 26)
            dp[1] = 2;
        
        for(int i = 2; i < s.length(); i++)
        {
            int dr = s[i] - '0';
            int dl = ((s[i - 1] - '0') * 10) + dr;
            // dp[i] = dp[i - 1];
            
            if(dl >= 10 && dl <= 26)
                dp[i] += dp[i - 2];
            
            if(dr > 0)
                dp[i] += dp[i - 1];
        }
        
        return dp[s.length() - 1];
    }
};