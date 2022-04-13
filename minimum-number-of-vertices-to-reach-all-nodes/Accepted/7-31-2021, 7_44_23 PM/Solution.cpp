// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

class Solution {
public:    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> res;
        
        for(auto i : edges)
        {
            if(visited[i[1]])
                continue;
            visited[i[1]] = true;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                res.push_back(i);
        }
        
        return res;
    }
};