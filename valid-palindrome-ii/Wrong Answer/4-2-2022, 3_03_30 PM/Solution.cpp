// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        bool once = false;
        
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            
            else
            {
                if(once == true)
                    return false;
                
                once = true;
                
                if(s[i + 1] == s[j])
                    i++;
                else if(s[i] == s[j - 1])
                    j--;
                else
                    return false;
            }
        }
        
        return true;
    }
};