// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool colorGraph(vector<vector<int>> &graph, vector<int> &color, int src, int col)
    {
        if(color[src] != -1)
            return color[src] == col;
        
        color[src] = col;
        
        for(auto i : graph[src])
        {   
            if(!colorGraph(graph, color, i, col ^ 1))
                return false;
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for(auto i : dislikes)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        vector<int> color(n + 1, -1);
        
        for(int i = 1; i <= n; i++)
        {
            if(color[i] == -1 && !colorGraph(graph, color, i, 0))
                return false;
        }
        
        return true;
    }
};