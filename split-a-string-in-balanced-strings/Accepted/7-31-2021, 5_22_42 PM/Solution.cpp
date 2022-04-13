// https://leetcode.com/problems/split-a-string-in-balanced-strings

class Solution {
public:
    int balancedStringSplit(string s) {
        int i = 0, j = 0;
        int count = 0;
        for(int k = 0; k < s.length(); k++)
        {
            if(s[k] == 'R')
                i++;
            if(s[k] == 'L')
                j++;
            if((i == j) && (i + j != 0))
            {
                count++;
                i = 0;
                j = 0;
            }
        }
        
        return count;
    }
};