// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> m(n);
        vector<int> indegree(n, 0);
        for(auto i : roads)
        {
            m[i[0]].insert(i[1]);
            m[i[1]].insert(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        
        int maxRank = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int sum = indegree[i] + indegree[j];
                if(m[i].find(j) != m[i].end())
                    sum--;
                maxRank = max(maxRank, sum);
            }
        }
        
        return maxRank;
    }
};