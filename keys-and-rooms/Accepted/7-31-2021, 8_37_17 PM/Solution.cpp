// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    void DFS(vector<vector<int>> &graph, vector<bool> &visited, int node)
    {
        visited[node] = true;
        
        for(auto i : graph[node])
        {
            if(!visited[i])
                DFS(graph, visited, i);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        DFS(rooms, visited, 0);
        
        for(auto i : visited)
        {
            if(!i)
                return false;
        }
        
        return true;
    }
};