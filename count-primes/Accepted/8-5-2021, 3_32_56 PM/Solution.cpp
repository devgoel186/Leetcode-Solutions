// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        vector<bool> count(n + 1, true);
        for(int i = 2; i * i <= n; i++)
        {
            for(int j = i * i; j <=n; j += i)
            {
                count[j] = false;
            }
        }
        
        int res = 0;
        for(int i = 2; i < n; i++)
        {
            if(count[i])
                res++;
        }
        return res;
    }
};