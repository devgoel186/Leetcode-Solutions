// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isAlNum(char ch)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z'))
            return true;
        return false;
            
    }
    
    char convert(char ch)
    {
        if(ch >= 'A' && ch <= 'Z')
            return ch + 32;
        return ch;
    }
    
    bool isPalindrome(string s) {
        
        /*
        ATTEMPT 1
        ---------
        string res = "";
        for(int i = 0; i < s.length(); i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                res += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                char ch = s[i] - 'A' + 'a';
                res += ch;
            }
        }
        
        string temp = "";
        for(int i = 0; i < res.length(); i++)
            temp = res[i] + temp;
        
        return temp == res;
        */
        
        for(int i = 0, j = s.length() - 1; i < j; i++, j--)
        {
            while(!isAlNum(s[i]) && i < j)
                i++;
            while(!isAlNum(s[j]) && i < j)
                j--;
            if(convert(s[i]) != convert(s[j]))
                return false;
        }
        
        return true;
    }
};