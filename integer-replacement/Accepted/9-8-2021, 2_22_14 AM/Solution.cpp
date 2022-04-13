// https://leetcode.com/problems/integer-replacement

#define ll long long
class Solution {
public:
    int calc(ll n) {
        if(n < 4) 
            return n - 1;
        if(n % 2 == 0) 
            return calc(n / 2) + 1;
        else {
            if((n + 1) % 4 == 0) 
                return calc((n + 1) / 2) + 2;
            else 
                return calc((n-1)/2)+2;
        }
    }
    
    int integerReplacement(int n) {
        if (n == INT_MAX) 
            return 32;
        return calc((ll)n);
    }
};