// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
        int l = max(num1.length(), num2.length());
        int s = min(num1.length(), num2.length());
        
        string sl, ss;
        if(num1.length() == l)
        {
            sl = num1;
            ss = num2;
        }
        else
        {
            sl = num2;
            ss = num1;
        }
        
        long long ans = 0;
        for(int i = 0; i < s; i++)
        {
            long long first = (ss[s - 1 - i] - '0') * pow(10, i);
            for(int j = 0; j < l; j++)
            {
                long long second = (sl[l - 1 - j] - '0') * pow(10, j);
                ans = ans + first * second;
            }
        }
        
        string res = "";
        if(ans == 0)
            return "0";
        
        while(ans != 0)
        {
            char digit = (ans % 10) + '0';
            res = digit + res; 
            ans /= 10;
        }
        
        return res;
    }
};