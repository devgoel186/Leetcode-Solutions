// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        for(int i = 0; i < edges.size(); i++)
        {
            m[edges[i][0]]++;
            m[edges[i][1]]++;
        }
        
        for(auto i : m)
        {
            if(i.second == edges.size())
                return i.first;
        }
        
        return 0;
    }
};