// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            xorAll ^= nums[i];
        }
        
        int rightmostSetBit = (xorAll & ~(xorAll - 1));
        int x = 0;
        int y = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(rightmostSetBit & nums[i])
                x ^= nums[i];
            else
                y ^= nums[i];
        }
        return {x, y};
    }
};