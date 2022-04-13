// https://leetcode.com/problems/count-substrings-that-differ-by-one-character

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.length(), n = t.length();
        int res = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(s[i] != t[j])
                {
                    int l = 1;
                    int r = 1;
                    
                    while(i - l >= 0 && j - l >= 0 && s[i - l] == t[j - l])
                        l++;
                    
                    while(i + r < s.size() && j + r < t.size() && s[i + r] == t[j + r])
                        r++;
                    
                    res += l * r;
                }
            }
        }
        
        return res;
    }
};