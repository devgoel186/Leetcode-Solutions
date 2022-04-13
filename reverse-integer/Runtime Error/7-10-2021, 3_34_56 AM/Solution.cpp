// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int32_t temp = x;
        int32_t rev = 0;

        while (temp != 0)
        {
            int32_t prev = rev;
            rev = rev * 10 + temp % 10;
            if ((rev - temp % 10) / 10 != prev)
                return 0;
            temp /= 10;
        }

        return rev;
    }
};