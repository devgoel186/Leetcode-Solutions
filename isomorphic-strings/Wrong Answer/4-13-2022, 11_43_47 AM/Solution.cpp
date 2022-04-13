// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, char> m;
        
        int i = 0;
        while(i < s.length())
        {
            if(m.find(s[i]) == m.end())
                m[s[i]] = t[i];
            
            else
                if(m[s[i]] != t[i])
                    return false;
            
            i++;
        }
        
        return true;
    }
};