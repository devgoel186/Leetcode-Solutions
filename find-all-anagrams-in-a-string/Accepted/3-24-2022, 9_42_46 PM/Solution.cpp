// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    /* Approach 1    
    
    bool compare(string a, string b)
    {
        sort(a.begin(), a.end());
        
        return a == b;
    }
    
    vector<int> findAnagrams(string s, string p) 
    {
        if(p.length() > s.length())
            return {};
        
        vector<int> ans;
        sort(p.begin(), p.end());
        for(int i = 0; i <= s.length() - p.length(); i++)
        {
            if(compare(s.substr(i, p.length()), p))
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
    */
    
    /* Approach 2 */
    
    vector<int> findAnagrams(string s, string p) 
    {    
        int m = s.length(), n = p.length();

        if(p.length() > s.length())
            return {};

        vector<int> pfreq(26, 0);
        vector<int> winfreq(26, 0);

        for(int i = 0; i < n; i++)
        {
            pfreq[p[i] - 'a']++;
            winfreq[s[i] - 'a']++;
        }

        vector<int> ans;
        if(pfreq == winfreq)
            ans.push_back(0);

        for(int i = n; i < m; i++)
        {
            winfreq[s[i - n] - 'a']--;
            winfreq[s[i] - 'a']++;

            if(winfreq == pfreq)
                ans.push_back(i - n + 1);
        }

        return ans;
    }
};