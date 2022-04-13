// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        int x = abs(divisor), y = abs(dividend);
        int count = 0;
        while(y >= x)
        {
            count++;
            y -= x;            
        }
        return count;
    }
};