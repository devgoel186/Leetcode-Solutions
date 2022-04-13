// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] + nums[nums.size() - i - 1] > max)
                max = nums[i] + nums[nums.size() - i - 1];
        }
        return max;
    }
};