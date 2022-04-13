// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        long long a = 0;
        long long b = 1;
        long long c = 1;
        long long d = 0;
        
        while(n--)
        {
            d = (a + b + c);
            a = b;
            b = c;
            c = d;
        }
        
        return (int)a;
    }
};