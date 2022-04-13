// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void reverse(vector<int> &nums, int l, int r)
    {
        int i = l, j = r;
        while(i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};