// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int start = 0, end = 0, n = nums.size();
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == n - 1 || nums[i] + 1 != nums[i + 1])
            {
                if(nums[i] != start)
                    res.push_back(to_string(start) + "->" + to_string(nums[i]));
                
                else
                    res.push_back(to_string(start));
                
                if(i != n - 1)
                    start = nums[i + 1];
            }
        }
        
        return res;
    }
};