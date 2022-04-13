// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, maxLen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close)
                maxLen = max(maxLen, open + close);
            else if(close > open)
                open = close = 0;
        }
        
        open = close = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close)
                maxLen = max(maxLen, open + close);
            else if(open > close)
                open = close = 0;
        }
        
        return maxLen;
    }
};