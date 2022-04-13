// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = s;
        
        int l = 0, r = s.size() - 1;
        for(int i = 0; i < s.size() - 1; i++)
        {
            s = s.substr(1) + s[0];
            
            if(s == goal)
                return true;
        }
        
        return false;
    }
};