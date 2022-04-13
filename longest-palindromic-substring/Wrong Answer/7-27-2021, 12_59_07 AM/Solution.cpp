// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        string pal;
        while(i < j)
        {
            if(s[i] == s[j])
            {
                pal += s[i];
                i++;
                j--;        
                if(i == j)
                {
                    return pal + s[i] + pal;
                }
                else if(i > j)
                {
                    return pal + pal;
                }
            }
            else
            {
                pal = "";
                j--;
            }
        }
        return pal;
    }
};