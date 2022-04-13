// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        for(int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dist[i][k] != INT_MAX && dist[k][j] !=  INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    
        // vector<vector<int>> adjl(n);
        // for(int i = 0; i < dist.size(); i++)
        // {            
        //     for(int j = 0; j < dist.size(); j++)   
        //     {
        //         if(dist[i][j] != 0 && dist[i][j] <= distanceThreshold)
        //         {
        //             adjl[i].push_back(j);
        //         }
        //     }
        // }
        
        
        int max = 0, minSize = INT_MAX;
        
        // for(int i = 0; i < adjl.size(); i++)
        // {
        //     if(adjl[i].size() <= minSize)
        //     {
        //         minSize = adjl[i].size();
        //         if(i > max)
        //             max = i;
        //     }
        // }
        
        for(int i = 0; i < n; i++)
        {
            int temp = 0;
            for(int j = 0; j < n; j++)
            {
                if(i != j && dist[i][j] <= distanceThreshold)
                    temp++;
            }
            if(temp <= minSize)
            {
                minSize = temp;
                if(i > max)
                    max = i;
            }
        }
        
        return max;
    }
};