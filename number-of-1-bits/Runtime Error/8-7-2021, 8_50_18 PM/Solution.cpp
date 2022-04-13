// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        int count = 0;
        while(n != 0)
        {
            int rsb = n & ~(n - 1);
            count++;
            n = n >> ((int)log2(rsb) + 1);
        }
        return count;
    }
};