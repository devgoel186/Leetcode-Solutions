// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int change(vector<vector<int>> &adjl, vector<bool> &visited, int src)
    {
        visited[src] = true;
        int sum = 0;
        
        for(auto i : adjl[src])
        {
            if(!visited[abs(i)])
            {
                if(i > 0)
                    sum++;
                sum += change(adjl, visited, abs(i));
            }
        }
        
        return sum;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjl(n);
        vector<bool> visited(n, false);
        
        for(auto i : connections)
        {
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(-i[0]);
        }
        
        return change(adjl, visited, 0);
    }
};