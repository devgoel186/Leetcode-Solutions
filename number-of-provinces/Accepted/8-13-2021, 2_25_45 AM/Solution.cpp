// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int src)
    {
        visited[src] = true;
        
        for(int i = 0; i < graph.size(); i++)
        {
            if(graph[src][i] == 1 && !visited[i])
                dfs(graph, visited, i);            
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        
        return count;
    }
};