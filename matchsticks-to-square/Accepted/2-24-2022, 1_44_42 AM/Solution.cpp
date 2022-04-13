// https://leetcode.com/problems/matchsticks-to-square

class Solution {
    int x = 0;
    
    private:
    bool dfs(vector<int> &m, vector<bool> &visited, int i, int sum, int k)
    { 
        if(k == 0)
            return true;
        
        if(sum == 0)
            return dfs(m, visited, 0, x / 4, k - 1);
        
        for(int j = i; j < m.size(); j++)
        {
            if(visited[j] || (sum - m[j] < 0))
                continue;
            
            visited[j] = true;
            if(dfs(m, visited, j + 1, sum - m[j], k))
                return true;
            visited[j] = false;
        }
        
        return false;
    }
    
    public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        int n = matchsticks.size();
        for(auto i : matchsticks)
            x += i;
        
        if((n < 4) || (x % 4 != 0))
            return false;
        
        vector<bool> visited(n, false);
        
        // for(auto i : visited)
        // {
        //     if(!visited[i])
        //         if(!dfs(matchsticks, visited, i, sum / 4))
        //             return false;
        // }
        
        return dfs(matchsticks, visited, 0, x / 4, 3);
    }
};