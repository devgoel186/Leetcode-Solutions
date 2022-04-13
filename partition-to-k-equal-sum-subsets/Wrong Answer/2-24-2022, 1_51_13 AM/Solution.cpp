// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
    private:
    int x = 0;
    
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto i : nums)
            x += i;
    
        if((n < k) || (x % k != 0))
            return false;
        
        vector<bool> visited(n, false);
        
        return dfs(nums, visited, 0, x / 4, k - 1);
    }
};