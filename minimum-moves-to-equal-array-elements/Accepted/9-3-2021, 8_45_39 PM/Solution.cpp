// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minElement = INT_MAX, sum = 0;
        
        for(auto i : nums)
        {
            sum += i;
            minElement = min(i, minElement);
        }
        
        
        int n = nums.size();
        return sum - n * minElement;
    }
};