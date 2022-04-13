// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        
        int l = 0;
        int len = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
                l = max(l, m[s[i]] + 1);
            m[s[i]] = i;            
            len = max(len, i - l + 1);
        }
        
        return len;
    }
};