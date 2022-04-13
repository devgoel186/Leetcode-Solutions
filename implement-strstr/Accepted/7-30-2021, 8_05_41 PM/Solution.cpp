// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        
        int found = -1;
        for(int i = 0; i < haystack.length(); i++)
        {
            if(haystack[i] == needle[0])
            {
                int x = i;
                int y = 0;
                while(y < needle.length() && x < haystack.length())
                {
                    if(needle[y] == haystack[x])
                    {
                        y++;
                        x++;
                    }
                    else
                        break;
                }
                if(y == needle.length())
                {
                    return i;
                }
            }
        }
        return -1;
    }
};