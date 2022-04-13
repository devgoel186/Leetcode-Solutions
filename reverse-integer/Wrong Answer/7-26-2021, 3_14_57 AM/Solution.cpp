// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        while(x != 0)      
        {
            sum = (sum * 10) + (x % 10);
            if(sum < 0)
                return 0;
            x /= 10;
        }
        return sum;
    }
};