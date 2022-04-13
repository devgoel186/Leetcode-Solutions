// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closest = nums[0] + nums[1] + nums[2];
        bool flag = false;
        
        for(int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                
                if(abs(sum - target) < abs(closest - target))
                    closest = sum;
                
                if(sum > target)
                    r--;
                else if(sum < target)
                    l++;
                else
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag)
                break;
        }
        
        return closest;
    }
};