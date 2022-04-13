// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool bfs(int n, vector<vector<int>>& adjl, int src, int dest)
    {
        if(src == dest)
            return true;
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int x = q.front();
            visited[x] = true;            
            q.pop();
            
            for(auto i : adjl[x])
            {
                if(!visited[i])
                {
                    if(i == dest)
                        return true;
                    q.push(i);
                }
            }            
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjl(n);
        
        for(auto i : edges)
        {
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
        
        return bfs(n, adjl, start, end);
    }
};