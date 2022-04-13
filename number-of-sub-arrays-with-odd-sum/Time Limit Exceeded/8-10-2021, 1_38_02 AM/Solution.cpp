// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;    
        for(int i = 1; i < arr.size(); i++)
            arr[i] += arr[i - 1];
        
        int x = 1, count = 0;
        while(x <= arr.size())
        {
            int sum = arr[x - 1];
            if(sum % 2 == 1)
                count = (count + 1) % 1000000007;
            for(int i = 1; i + x - 1 < arr.size(); i++)
            {
                sum = arr[i + x - 1] - arr[i - 1];
                if(sum % 2 == 1)
                    count = (count + 1) % 1000000007;
            }
            x++;
        }
        return count;
    }
};