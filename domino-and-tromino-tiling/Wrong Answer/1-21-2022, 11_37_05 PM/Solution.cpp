// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int mod = 1e9 + 7;
    
    int numTilings(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;
        
        int x = (numTilings(n - 1) % mod + numTilings(n - 2) % mod) % mod;
        int y = (numTilings(n - 3) % mod + 5 % mod) % mod;
        
        return (x + y) % mod;
    }
};