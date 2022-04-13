// https://leetcode.com/problems/happy-number

class Solution {
public:
    long long sumSquare(int n)
    {
        long long sum = 0;
        while(n != 0)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) 
    {
        long long sumSlow = sumSquare(n);
        long long fastSum = sumSquare(sumSlow);
        
        if(sumSlow == 1 || fastSum == 1)
            return true;
        
        while(sumSlow != fastSum)
        {
            sumSlow = sumSquare(sumSlow);
            fastSum = sumSquare(sumSquare(fastSum));
            
            if(sumSlow == 1 || fastSum == 1)
                return true;
        }
        
        return false;
    }
};