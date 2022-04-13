// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            xorAll ^= nums[i];
        }
        
        long long rightmostSetBit = (xorAll & ~(xorAll - 1));
        long long x = 0;
        long long y = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(rightmostSetBit & nums[i])
                x ^= nums[i];
            else
                y ^= nums[i];
        }
        return {(int)x, (int)y};
    }
};