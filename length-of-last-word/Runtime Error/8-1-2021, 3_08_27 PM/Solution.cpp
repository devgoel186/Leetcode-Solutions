// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        string last = "";      
        int max = 0;
        while(s[s.length() - 1] == ' ')
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
                if(max < last.length())
                    max = last.length();
            }
        }
        return max;
    }
};