// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

// class Solution {
//     private:
//     int x = 0;
    
//     bool dfs(vector<int> &m, vector<bool> &visited, int i, int sum, int k)
//     { 
//         if(k == 0)
//             return true;
        
//         if(sum == 0)
//             return dfs(m, visited, 0, x / k, k - 1);
        
//         for(int j = i; j < m.size(); j++)
//         {
//             if(visited[j] || (sum - m[j] < 0))
//                 continue;
            
//             visited[j] = true;
            
//             if(dfs(m, visited, j + 1, sum - m[j], k))
//                 return true;
            
//             visited[j] = false;
//         }
        
//         return false;
//     }
    
//     public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int n = nums.size();
//         for(auto i : nums)
//             x += i;
    
//         if((n < k) || (x % k != 0))
//             return false;
        
//         vector<bool> visited(n, false);
        
//         return dfs(nums, visited, 0, x / k, k - 1);
//     }
// };

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) return false;
        
        vector<int>visited(nums.size(), false);
        return backtrack(nums, visited, sum / k, 0, 0, k);
    }
    
    bool backtrack(vector<int>& nums,vector<int>visited, int target, int curr_sum, int i, int k) {
        if (k == 1) 
            return true;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
            visited[j] = false;
        }
        
        return false;
    }
};