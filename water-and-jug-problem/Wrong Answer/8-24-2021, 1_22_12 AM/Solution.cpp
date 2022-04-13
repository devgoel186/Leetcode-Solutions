// https://leetcode.com/problems/water-and-jug-problem

class Solution {
public:
    bool canMeasureWater(int a, int b, int target) {
        if(a + b == target)
            return true;
        if(a + b < target)
            return false;
        if(target % abs(a - b) == 0)
            return true;
        if(target % a == 0 || target % b == 0)
            return true;
        return false;
    }
};