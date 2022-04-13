// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0, curr = 0;
        map<char, int> m;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
                curr = max(curr, m[s[i]] + 1);
            
            m[s[i]] = i;
            mx = max(mx, i - curr + 1);
        }
        
        return mx;
    }
};