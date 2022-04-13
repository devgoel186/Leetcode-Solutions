// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
    private:
    int calculate(int i)
    {
        return (i * (i - 1)) / 2;
    }
    
    public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        int sum = 0;
        
        for(auto i : nums)
        {
            sum += (i % k + k) % k;
            count[(sum % k)]++;
        }
        
        int res = calculate(count[0]) + count[0];
        for(int i = 1; i < k; i++)
            res += calculate(count[i]);
        
        return res;
    }
};