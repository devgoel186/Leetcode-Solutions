// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int index = 0, i = 0;
        while(i < g.size() && index < s.size())
        {
            if(s[index] >= g[i])
                i++;
            index++;
        }
        return i;
    }
};