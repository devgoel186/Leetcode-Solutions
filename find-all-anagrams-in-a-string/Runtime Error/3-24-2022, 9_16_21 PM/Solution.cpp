// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    bool compare(string a, string b)
    {
        sort(a.begin(), a.end());
        
        return a == b;
    }
    
    vector<int> findAnagrams(string s, string p) 
    {
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
};