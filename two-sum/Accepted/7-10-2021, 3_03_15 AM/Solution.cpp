// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> h;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (h.find(target - nums[i]) != h.end())
        {
            res.push_back(i);
            res.push_back(h.find(target - nums[i])->second);
            return res;
        }
        h.insert(make_pair(nums[i], i));
    }
    return res;
    }
};