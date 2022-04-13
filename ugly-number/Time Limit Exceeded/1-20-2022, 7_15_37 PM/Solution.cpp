// https://leetcode.com/problems/ugly-number

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        
        vector<int> arr(n);
        for(int i = 1; i <= n; i++)
            arr[i - 1] = i;
        
        for(int i = 2; i <= n; i++)
        {
            if(arr[i - 1] == i)
            {
                for(int j = i * i; j <= n; j += i)
                {
                    if(arr[j - 1] == j)
                        arr[j - 1] = i;
                }
            }
        }
        
        while(n > 1)
        {
            if(arr[n - 1] != 2 && arr[n - 1] != 3 && arr[n - 1] != 5)
                return false;
            n /= arr[n - 1];
        }
        
        return true;
    }
};