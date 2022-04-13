// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool colorGraph(vector<vector<int>> &graph, vector<int> &color, int pos)
    {   
        for(auto i : graph[pos])
        {
            if(color[i] == -1)
            {
                color[i] = (color[pos] == 1) ? 0 : 1;
                if(!colorGraph(graph, color, i))
                    return false;
            }
            
            else if(color[i] == color[pos])
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {        
        int n = graph.size();
        
        vector<int> color(n, -1);
        color[0] = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(!colorGraph(graph, color, i))
                return false;
            }
        }
        
        return true;
    }
};