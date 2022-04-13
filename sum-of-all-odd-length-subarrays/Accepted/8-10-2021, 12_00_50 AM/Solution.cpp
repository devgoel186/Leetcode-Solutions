// https://leetcode.com/problems/sum-of-all-odd-length-subarrays

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        int sum = arr[0];
        for(int i = 1; i < arr.size(); i++)
        {
            sum += arr[i];
            arr[i] += arr[i - 1];
        }
        
        int x = 3;
        while(x <= arr.size())
        {
            sum += arr[x - 1];
            for(int i = 1; i + x - 1 < arr.size(); i++)
            {
                sum += arr[i + x - 1] - arr[i - 1];
            }
            x += 2;
        }
        
        return sum;
    }
};