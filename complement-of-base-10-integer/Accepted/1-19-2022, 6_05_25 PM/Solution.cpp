// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        
        return pow(2, floor(log2(n)) + 1) - n - 1;
    }
};