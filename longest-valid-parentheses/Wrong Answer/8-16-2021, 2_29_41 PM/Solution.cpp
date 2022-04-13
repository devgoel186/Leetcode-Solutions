// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    bool match(char a, char b)
    {
        if(a == '(' && b == ')')
            return true;
        return false;
    }
    
    int longestValidParentheses(string s) {
        stack<char> st;
        int i = 0, len = 0, maxLen = 0;
        
        while(i < s.length())
        {
            if(st.empty() || !match(st.top(), s[i]))
            {
                // if(st.empty() && len > maxLen)
                // {
                //     maxLen = len;
                //     len = 0;
                // }
                st.push(s[i]);
            }
            else
            {
                len += 2;
                st.pop();
                
                if(st.empty())
                {
                    maxLen += len;
                    len = 0;
                }
                else
                {
                    maxLen = max(len, maxLen);
                    // len = 0;
                }
            }
            i++;
        }
        
        maxLen = max(len, maxLen);
        
        return maxLen;
    }
};