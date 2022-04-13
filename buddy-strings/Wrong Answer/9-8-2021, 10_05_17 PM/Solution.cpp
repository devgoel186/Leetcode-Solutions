// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        
        int n = s.size();
        unordered_map<char, int> m;
        char duplicate = '*';
        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;
            if(m[s[i]] >= 2)
                duplicate = s[i];
        }
        
        if(s == goal && duplicate == '*')
            return false;
        
        for(int i = 0; i < n; i++)
        {
            if(m.find(goal[i]) == m.end())
                return false;
            m[goal[i]]--;
            if(m[goal[i]] < 0)
                return false;
        }
        
        return true;
    }
};