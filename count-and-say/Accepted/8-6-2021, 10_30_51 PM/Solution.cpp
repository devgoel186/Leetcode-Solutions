// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = countAndSay(n - 1);
        
        int index = 1;
        char num = s[0];
        string res = "";
        for(int i = 1; i < s.length(); i++)
        {
            if(num == s[i])
                index++;
            else
            {
                char times = index + '0';
                res = res + times + num;
                index = 1;
                num = s[i];
            }
        }
        char times = index + '0';
        res = res + times + num;
        return res;
    }
};