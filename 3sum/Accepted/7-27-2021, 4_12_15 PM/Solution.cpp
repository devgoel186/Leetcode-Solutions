// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j, k;
        set<vector<int>> s;
        if(nums.size() <= 2)
            return {};
        for(int i = 0; i <= nums.size() - 3; i++)
        {
            j = i + 1;
            k = nums.size() - 1;
            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
            }
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};