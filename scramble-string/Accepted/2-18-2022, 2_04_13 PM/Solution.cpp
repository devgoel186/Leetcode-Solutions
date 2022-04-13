// https://leetcode.com/problems/scramble-string

class Solution {
public:
    bool checkAnagram(string a, string b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    
    bool helper(unordered_map<string, bool> &m, string x, string y)
    {
        if(x.length() != y.length())
            return false;
        
        int n = x.length();
        
        if(n == 0)
            return true;
        
        if(x == y)
            return true;
        
        if(!checkAnagram(x, y))
            return false;
        
        string key = x + "-" + y;
        
        if(m.find(key) != m.end())
            return m[key];
        
        bool flag = false;
        
        for(int i = 1; i < n; i++)
        {
            if(helper(m, x.substr(0, i), y.substr(0, i)) && helper(m, x.substr(i, n - i), y.substr(i, n - i)))
                flag = true;
            
            if(helper(m, x.substr(0, i), y.substr(n - i, i)) && helper(m, x.substr(i, n - i), y.substr(0, n - i)))
                flag = true;
        }
        
        return m[key] = flag;
    }
    
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> m;
     
        return helper(m, s1, s2);
    }
};