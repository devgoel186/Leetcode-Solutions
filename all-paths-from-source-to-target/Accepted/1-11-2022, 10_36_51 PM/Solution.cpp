// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    void dfs(vector<vector<int>> &adjl, int src, int dest, vector<int> &ans, vector<vector<int>> &res)
    {
        ans.push_back(src);
        
        if(src == dest)
        {
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        
        for(auto i : adjl[src])
            dfs(adjl, i, dest, ans, res);
        
        ans.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> ans;
        dfs(graph, 0, graph.size() - 1, ans, res);
        
        return res;
    }
};