// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int>> p;
        for(auto i : envelopes)
            p.push_back(make_pair(i[0], i[1]));
                     
        int count = 0;
        sort(p.begin(), p.end(), greater<pair<int, int>>());
        
        // for(auto i : )
        
        int x = p[0].first, y = p[0].second;
        for(int i = 0; i < p.size() - 1; i++)
        {
            if(p[i + 1].first < x && p[i + 1].second < y)
            {
                x = p[i + 1].first;
                y = p[i + 1].second;
                count++;
            }
            else
                continue;
        }
                        
        return count + 1;
    }
};