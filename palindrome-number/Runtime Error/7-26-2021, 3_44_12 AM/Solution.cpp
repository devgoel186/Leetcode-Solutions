// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x, sum = 0;
        while (temp != 0)
        {
            sum = (sum * 10) + (temp % 10);
            temp /= 10;
        }
        return sum == abs(x);
    }
};