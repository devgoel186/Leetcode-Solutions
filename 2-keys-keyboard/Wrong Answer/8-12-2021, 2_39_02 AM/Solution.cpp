// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:
    bool isPrime(int n)
    {
        for(int i = 3; i <= sqrt(n); i += 2)
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    
    int maxDivisor(int n)
    {
        int div = 1;
        for(int i = 3; i <= (n/2); i += 2)
        {
            if(n % i == 0)
                div = max(div, i);
        }
        return div;
    }
    
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        
        if(n == 1)
            return 0;
        else if(n <= 5)
            return n;
        
        for(int i = 2; i <= 5; i++)
            dp[i] = i;
        
        for(int i = 6; i <= n; i++)
        {
            if(n & 1)
            {
                if(isPrime(i))
                    dp[i] = i;
                else
                {
                    int div = maxDivisor(i);
                    dp[i] = dp[div] + 1 + (int)(i / div);
                }
            }
            else
            {
                dp[i] = dp[i/2] + 2;
            }
        }
        
        return dp[n];
    }
};