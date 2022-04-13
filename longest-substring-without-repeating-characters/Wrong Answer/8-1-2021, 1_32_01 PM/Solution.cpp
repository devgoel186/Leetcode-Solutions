// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int globalMax = 0;
        int max = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) == m.end())
            {
                m[s[i]]++;
                max++;
            }
            else
            {
                if(max > globalMax)
                    globalMax = max;
                max = 0;
                m.clear();
                i--;
            }            
        }
        
        if(max > globalMax)
            globalMax = max;
        return globalMax;
    }
};