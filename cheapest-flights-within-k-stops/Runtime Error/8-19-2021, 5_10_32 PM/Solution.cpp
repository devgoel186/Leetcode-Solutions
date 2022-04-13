// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>> &adjl, int src, int dest, int k)
    {
        // vector<int> dist(adjl.size(), 1e5);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, k + 1});
        
        while(!pq.empty())
        {
            vector<int> x = pq.top();
            pq.pop();
            
            int d = x[0];
            int u = x[1];
            int kval = x[2];
            
            if(kval < 0)
                continue;
            
            if(u == dest)
                return d;
            
            for(auto i : adjl[u])
            {
                int v = i.first;
                int w = i.second;
                
                pq.push({d + w, v, kval - 1});
                
                // if(dist[v] > dist[u] + w)
                // {
                    // dist[v] = dist[u] + w;                    
                // }
            }
        }
        
        return -1;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjl(flights.size());
        
        for(int i = 0; i < flights.size(); i++)
        {       
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adjl[u].push_back({v, w});
        }
        
        return dijkstra(adjl, src, dst, k);
        
    }
};