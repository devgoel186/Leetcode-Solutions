// https://leetcode.com/problems/ugly-number

class Solution {
public:
    bool isUgly(int n) {
        vector<int> arr(n + 1);
        for(int i = 0; i <= n; i++)
            arr[i] = i;
        
        for(int i = 2; i <= n; i++)
        {
            if(arr[i] == i)
            {
                for(int j = i * i; j <= n; j += i)
                {
                    if(arr[j] == j)
                        arr[j] = i;
                }
            }
        }
        
        while(n > 1)
        {
            if(arr[n] != 2 && arr[n] != 3 && arr[n] != 5)
                return false;
            n /= arr[n];
        }
        
        return true;
    }
};