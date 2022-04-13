// https://leetcode.com/problems/matchsticks-to-square

class Solution {
    private:
    bool dfs(vector<int> &m, vector<bool> &visited, int i, int sum, int k, int target)
    { 
        if(k == 0)
            return true;
        
        if(sum == target)
            return dfs(m, visited, 0, 0, k - 1, target);
        
        for(int j = i; j < m.size(); j++)
        {
            if(visited[j] || (m[i] + sum > target))
                continue;
            
            visited[j] = true;
            if(dfs(m, visited, j + 1, sum + m[j], k, target))
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
            sum += i;
        
        if((n < 4) || (sum % 4 != 0))
            return false;
        
        vector<bool> visited(n, false);
        
        // for(auto i : visited)
        // {
        //     if(!visited[i])
        //         if(!dfs(matchsticks, visited, i, sum / 4))
        //             return false;
        // }
        
        return dfs(matchsticks, visited, 0, 0, 3, sum / 4);
    }
};