// https://leetcode.com/problems/maximum-69-number

class Solution {
public:
    int maximum69Number (int num) {
        int p = pow(10, floor(log10(num)));
        
        
        while(p > 0)
        {
            if((num / p) % 10 == 6)
            {
                num += 3 * p;              
                break;
            }
            p /= 10;
        }
        return num;
    }
};