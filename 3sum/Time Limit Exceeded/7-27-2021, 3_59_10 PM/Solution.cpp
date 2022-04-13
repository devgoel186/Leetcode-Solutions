// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int j, k;
        for(int i = 0; i <= nums.size() - 3; i++)
        {
            j = i + 1;
            k = nums.size() - 1;
            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    break;
                }
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
};