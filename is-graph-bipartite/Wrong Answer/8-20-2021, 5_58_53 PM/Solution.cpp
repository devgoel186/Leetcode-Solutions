// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool colorGraph(vector<vector<int>> &graph, vector<int> &color, int pos, int state)
    {   
        for(auto i : graph[pos])
        {
            if(color[i] == -1)
            {
                color[i] = state;
                if(!colorGraph(graph, color, i, (state xor 1)))
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
        
        // for(int i = 0; i < n; i++)
        // {
        //     if(color[i] == -1)
        //     {
        //         color[i] == 0;
        //         if(!colorGraph(graph, color, i, 0));
        //             return false;
        //     }
        // }
        
//         if(is)
        
//         return true;
        
        return colorGraph(graph, color, 0, 0);
    }
};