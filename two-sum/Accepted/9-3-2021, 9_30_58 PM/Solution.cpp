// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& p, int target) {
        vector<pair<int, int>> nums;
        for(int i = 0; i < p.size(); i++)
            nums.push_back({p[i], i});
        
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        
        while(i < j)
        {
            if(nums[i].first + nums[j].first == target)
                return {nums[i].second, nums[j].second};
            else if(nums[i].first + nums[j].first < target)
                i++;
            else
                j--;
        }
        
        return {};
    }
};