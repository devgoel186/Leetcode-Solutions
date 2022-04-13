// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

class Solution {
public:
    int dijkstra(int n, int src, vector<vector<pair<int, int>>> &adjl)
    {
        int count = 0;
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty())
        {
            pair<int, int> x = pq.top();
            pq.pop();
            int u = x.second;
            
            for(auto i : adjl[u])
            {
                int v = i.first;
                int w = i.second;
                
                if(v == n - 1)
                    count++;
                
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return count;
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjl(n);
        
        for(auto i : roads)
        {
            adjl[i[0]].push_back({i[1], i[2]});
            adjl[i[1]].push_back({i[0], i[2]});
        }
        
        return dijkstra(n, 0, adjl);
    }
};