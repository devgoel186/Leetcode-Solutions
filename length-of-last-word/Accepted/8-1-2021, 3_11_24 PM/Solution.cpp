// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        string last = "";      
        int max = 0;
        while(s.length() != 0 && s[s.length() - 1] == ' ')
        {
            s = s.substr(0, s.length() - 1);
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                last = "";
            }
            else
            {
                last += s[i];
            }
        }
        return last.length();
    }
};