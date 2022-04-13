// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    int findSet(vector<int> &parent, int v)
    {
        if(parent[v] == v)
            return v;
        parent[v] = findSet(parent, parent[v]);
        return parent[v];
    }
    
    void unionSet(vector<int> &parent, vector<int> &sizes, int u, int v)
    {
        int x = findSet(parent, u);
        int y = findSet(parent, v);
        if(x != y)
        {
            if(sizes[x] > sizes[y])
                swap(x, y);
            parent[x] = y;
            sizes[y] += x;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> sizes(n + 1, 1);
        
        for(int i = 0; i < n + 1; i++)
            parent[i] = i;            
            
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int x = findSet(parent, u);
            int y = findSet(parent, v);
            if(x == y)
                return {u, v};
            else
                unionSet(parent, sizes, x, y);
        }
        
        return {};
    }
};