// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 3; j >= 0; j--)
            {
                dp[j] = dp[j] + dp[j + 1];
            }   
        }    
        
        int ans = 0;
        
        for(auto i : dp)
            ans += i;
        
        return ans;
    }
};