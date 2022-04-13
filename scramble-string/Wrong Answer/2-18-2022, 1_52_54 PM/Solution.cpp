// https://leetcode.com/problems/scramble-string

class Solution {
public:
    bool helper(unordered_map<string, bool> &m, string x, string y)
    {
        if(x.length() != y.length())
            return false;
        if(x.length() == 0)
            return true;
        if(x == y)
            return true;
        
        string key = x + "-" + y;
        
        if(m.find(key) != m.end())
            return m[key];
        
        int n = x.length();
        bool flag = false;
        
        for(int i = 1; i < n; i++)
        {
            if(helper(m, x.substr(0, i), y.substr(0, i)) && helper(m, x.substr(i, n - i), y.substr(i, n - i)))
                flag = true;
            
            if(helper(m, x.substr(0, i), y.substr(i, n - i)) && helper(m, x.substr(i, n - i), y.substr(0, i)))
                flag = true;
        }
        
        return m[key] = flag;
    }
    
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> m;
     
        return helper(m, s1, s2);
    }
};