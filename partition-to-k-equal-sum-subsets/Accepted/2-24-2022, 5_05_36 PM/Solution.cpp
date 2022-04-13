// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
    int x = 0;
    int doo = 0;
    
    private:
    bool dfs(vector<int> &m, vector<bool> &visited, int i, int sum, int k, int &unvisited)
    { 
        if(k == 0)
            return true;
        
        if(unvisited == 0 || i >= m.size())
            return false;
        
        if(sum == 0)
            return dfs(m, visited, 0, x / doo, k - 1, unvisited);
        
        for(int j = i; j < m.size(); j++)
        {
            if(visited[j] || (sum - m[j] < 0))
                continue;
            
            visited[j] = true;
            unvisited--;
            if(dfs(m, visited, j + 1, sum - m[j], k, unvisited))
                return true;
            
            unvisited++;
            visited[j] = false;
        }
        
        return false;
    }
    
    public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        doo = k;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(auto i : nums)
            x += i;
    
        if((n < k) || (x % k != 0))
            return false;
        
        int unvisited = nums.size();
        
        vector<bool> visited(n, false);
        
        return dfs(nums, visited, 0, x / k, k - 1, unvisited);
    }
};