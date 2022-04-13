// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    void DFS(vector<vector<int>>& graph, int node, vector<int> &ans, vector<vector<int>> &res)
    {
        ans.push_back(node);
        
        if(node == graph.size() - 1)
            res.push_back(ans);
        
        else
        {
            for(int i = 0; i < graph[node].size(); i++)
                DFS(graph, graph[node][i], ans, res);
        }
        
        ans.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> ans;
        vector<vector<int>> res;
        DFS(graph, 0, ans, res);
        return res;
    }
};