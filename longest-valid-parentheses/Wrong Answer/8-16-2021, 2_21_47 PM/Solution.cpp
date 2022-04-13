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
        int i = 0, len = 0;
        
        while(i < s.length())
        {
            if(st.empty() || !match(st.top(), s[i]))
            {
                st.push(s[i]);
            }
            else
            {
                len += 2;
                st.pop();
            }
            i++;
        }
        
        return len;
    }
};