// https://leetcode.com/problems/count-integers-with-even-digit-sum

class Solution {
public:
    int countEven(int num) {
        int sum = 0, temp = num;
        while(num)
        {
            sum += num % 10;
            num /= 10;
        }
        
        return (temp - sum % 2) / 2;
    }
};