// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1)
            return s.length();
        
        unordered_map<char, int> m;
        int count = 0, maxLength = 0;
        bool flag = false;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
            {
                flag = true;
                maxLength = max(i - m[s[i]], maxLength);
                m[s[i]] = i;
            }
            
            else
                m[s[i]] = i;
        }
        
        if(flag)
            return maxLength;
        
        return s.length();
    }
};