// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool colorGraph(vector<vector<int>> &graph, vector<int> &color, int src, int col)
    {
        if(color[src] != -1)
            return color[src] == col;
        
        color[src] = col;
        
        for(int i = 0; i < graph[src].size(); i++)
        {   
            if(!colorGraph(graph, color, graph[src][i], col ^ 1))
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1 && !colorGraph(graph, color, i, 0))
                return false;
        }        
        
        return true;
    }
};