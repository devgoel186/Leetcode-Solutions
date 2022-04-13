// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>> &adjl, int src)
    {
        vector<int> dist(adjl.size(), 1e9);
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
                
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int maxVal = -1;
        bool flag = false;
        for(int i = 1; i < dist.size(); i++)
        {
            if(dist[i] == 1e9)
            {
                flag = true;
                break;
            }
            maxVal = max(maxVal, dist[i]);
        }
        
        if(flag)
            return -1;
        return maxVal;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjl(n + 1);
        
        for(int i = 0; i < times.size(); i++)
        {       
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adjl[u].push_back({v, w});
        }
        
        return dijkstra(adjl, k);
    }
};