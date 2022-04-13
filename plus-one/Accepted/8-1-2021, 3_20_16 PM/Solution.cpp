// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(i == n - 1)
                digits[i] += carry + 1;
            else
                digits[i] += carry;
            
            if(digits[i] > 9)
            {
                digits[i] %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
                break;
            }
        }
        
        if(carry == 1)
        {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            return res;
        }
        return digits;
    }
};