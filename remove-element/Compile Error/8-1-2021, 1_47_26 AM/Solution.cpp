// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(auto i : x)
            if(i != val)
                nums[index++] = i;
        return index;
    }
};