// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int count = 0, maxLength = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            count++;
            if(m.find(s[i]) != m.end())
            {
                maxLength = max(count - m[s[i]] - 1, maxLength);
                m[s[i]] = i;
            }
            
            else
                m[s[i]] = i;
        }
        
        return maxLength;
    }
};