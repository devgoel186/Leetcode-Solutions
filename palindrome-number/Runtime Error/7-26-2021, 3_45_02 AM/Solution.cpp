// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x, sum = 0;
        while (temp != 0)
        {
            if(sum < 0)
                return false;
            sum = (sum * 10) + (temp % 10);
            temp /= 10;
        }
        return sum == abs(x);
    }
};