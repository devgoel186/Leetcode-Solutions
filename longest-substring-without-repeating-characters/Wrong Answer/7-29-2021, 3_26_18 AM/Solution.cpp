// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
            {
                break;
            }
            else
            {
                m[s[i]] = 1;
                res++;
            }
        }
        return res;
    }
};