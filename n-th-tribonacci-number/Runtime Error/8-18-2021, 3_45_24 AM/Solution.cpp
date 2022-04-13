// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        int d = 0;
        while(n--)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        
        return a;
    }
};