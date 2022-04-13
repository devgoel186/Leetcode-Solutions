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
                res = res + (char)(index + '0') + num;
                index = 1;
                num = s[i];
            }
        }
        res = res + (char)(index + '0') + num;
        return res;
    }
};