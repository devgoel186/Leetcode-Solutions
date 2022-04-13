// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        int count = 0;
        while(count != 32)
        {
            ans = ans << 1;
            ans += (n & 1);
            n >>= 1;
            count++;
        }
        
        return ans;
    }
};