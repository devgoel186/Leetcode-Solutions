// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx = 1, currmx = 1;
        for(int i = 1; i < nums.size(); i++)      
        {
            if(nums[i] > nums[i - 1])
                currmx++;
            else
                currmx = 1;
            
            if(currmx > mx)
                mx = currmx;
        }
        
        return mx;
    }
};