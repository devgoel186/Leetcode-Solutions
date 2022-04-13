// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        for(int i = 0; i < nums.size(); i++)
        {
            s.insert(make_pair(nums[i], i));
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int el = nums[i];
            if(s.find(target - el) != s.end())
            {
                vector<int> v;
                v.push_back(i);
                v.push_back(s[target - el]);
                return v;
            }
        }
        vector<int> v;
        return v;
    }
};