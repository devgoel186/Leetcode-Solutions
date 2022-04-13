// https://leetcode.com/problems/sum-of-all-odd-length-subarrays

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> res;
        if(arr.size() == 0)
            return 0;
        res.push_back(arr[0]);
        int sum = arr[0];
        for(int i = 1; i < arr.size(); i++)
        {
            sum += arr[i];
            res.push_back(res[i - 1] + arr[i]);        
        }
        
        int x = 3;
        while(x <= arr.size())
        {
            sum += res[x - 1];
            for(int i = 1; i + x - 1 < arr.size(); i++)
            {
                sum += res[i + x - 1] - res[i - 1];
            }
            x += 2;
        }
        
        return sum;
    }
};