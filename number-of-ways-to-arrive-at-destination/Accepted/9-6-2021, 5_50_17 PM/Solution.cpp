// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    const ll MOD = 1e9 + 7;
    /*
    int dijkstra(int n, int src, vector<vector<pair<ll, ll>>> &adjl)
    {   
        vector<ll> dist(n, INT_MAX), count(n, 0);
        dist[src] = 0;
        count[src] = 1;
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, src});
        
        while(!pq.empty())
        {
            pair<ll, ll> x = pq.top();
            pq.pop();
            ll u = x.second;
            
            if(x.first > dist[u])
                continue;
            
            for(auto i : adjl[u])
            {
                ll v = i.first;
                ll w = i.second;                

                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                    count[v] = count[u];
                }
                else if(dist[v] == dist[u] + w)
                {
                    count[v] = (count[v] % MOD + count[u] % MOD) % MOD;
                }
            }
        }
        
        return (int)count[n - 1] % MOD;
    }
    */
    
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adjl(n);
        
        for(auto i : roads)
        {
            adjl[i[0]].push_back({i[1], i[2]});
            adjl[i[1]].push_back({i[0], i[2]});
        }
        
        return dijkstra(adjl, n, 0);
    }
};