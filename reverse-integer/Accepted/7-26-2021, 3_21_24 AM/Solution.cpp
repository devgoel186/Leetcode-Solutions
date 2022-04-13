// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        while(x != 0)      
        {
            int unit = x % 10;
            x /= 10;
            if (sum > (INT_MAX / 10) || (sum == INT_MAX / 10 && unit > 7))
                return 0;
            if (sum < INT_MIN / 10 || (sum == INT_MIN / 10 && unit < -8))
                return 0;
            sum = sum * 10 + unit;
        }
        return sum;
    }
};