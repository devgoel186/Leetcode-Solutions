// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int dijkstra(int n, int src, vector<vector<pair<int, int>>> &adjl)
    {   
        vector<int> dist(n, INT_MAX), count(n, 0);
        dist[src] = 0;
        count[src] = 1;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty())
        {
            pair<int, int> x = pq.top();
            pq.pop();
            int u = x.second;
            
            if(x.first > dist[u])
                continue;
            
            for(auto i : adjl[u])
            {
                int v = i.first;
                int w = i.second;                
                
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                    count[v] = count[u];
                }
                else if(dist[v] == dist[u] + w)
                {
                    count[v] = (count[v] + count[u]) % MOD;
                }
            }
        }
        
        return count[n - 1];
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