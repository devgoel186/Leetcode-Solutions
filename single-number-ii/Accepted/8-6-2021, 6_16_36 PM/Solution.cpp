// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> arr(32, 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 31; j >= 0; j--)
            {
                if((nums[i] >> j) & 1)
                {
                    arr[31 - j]++;
                    arr[31 - j] %= 3;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            res = (res << 1) + arr[i];
        }
        return res;
    }
};