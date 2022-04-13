// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
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
    }
};