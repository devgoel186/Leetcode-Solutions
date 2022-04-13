// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool helper(string &s, int i, int j, int flag)
    {
        if(flag > 1)
            return false;
        
        while(i < j)
        {
            if(s[i] == s[j])
                return helper(s, i + 1, j - 1, flag);
            
            else
                return helper(s, i + 1, j, flag + 1) || helper(s, i, j - 1, flag + 1);
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        return helper(s, i, j, 0);
    }
};