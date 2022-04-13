// https://leetcode.com/problems/airplane-seat-assignment-probability

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n < 2)
            return 1.0;
        return 0.5;
    }
};