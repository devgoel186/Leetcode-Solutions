// https://leetcode.com/problems/three-divisors

class Solution {
public:
    bool isThree(int n) {
        if(n <= 3)
            return false;
        
        double x = sqrt(n);
        
        if(ceil(x) != floor(x))
            return false;
        
        int count = 0;
        for(int i = 1; i <= x / 2; i++)
        {
            if((int)x % i == 0)
                count++;
        }
        
        return count == 1;
    }
};