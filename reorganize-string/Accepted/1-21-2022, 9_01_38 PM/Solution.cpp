// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> m(26, 0);
        int maxfreq = 0;
        
        for(auto i : s)
        {
            if(++m[i - 'a'] > m[maxfreq])
                maxfreq = i - 'a';
        }
        
        if(m[maxfreq] > (s.size() + 1) / 2)
            return "";
        
        int i = 0;
        while(m[maxfreq])
        {
            s[i] = 'a' + maxfreq;
            m[maxfreq]--;
            i += 2;
        }
        
        int j = i;
        for(int i = 0; i < 26; i++)
        {
            while(m[i] > 0)
            {
                if(j >= s.size())
                    j = 1;
                
                s[j] = 'a' + i;
                m[i]--;
                j += 2;
            }
        }
        
        return s;
    }
};