// https://leetcode.com/problems/water-and-jug-problem

class Solution {
public:
    bool canMeasureWater(int a, int b, int target) {
        if(a + b == target || a == target || b == target)
            return true;
        if(a + b < target)
            return false;
        if(target % __gcd(a, b) == 0) // Bezout's identity
            return true;
        return false;
    }
};