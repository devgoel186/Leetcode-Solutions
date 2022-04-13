// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int expand(string s, int i, int j)
    {
        while(i >= 0 && j < s.length() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j - i - 1;
    }
    
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        
        int len = 0, start = 0, end = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i + 1);
            len = max(l1, l2);
            if(len > end - start)
            {
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};