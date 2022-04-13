// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool bfs(vector<vector<int>> &adjl, int a, int b, int n)
    {
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(a);
        visited[a] = true;
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            
            for(auto i : adjl[x])
            {
                if(i == b)
                    return true;
                
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(n <= 1)
            return false;
        
        vector<vector<int>> adjl(n);
        
        for(auto i : edges)
        {
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
        
        return bfs(adjl, start, end, n);
    }
};