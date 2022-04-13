// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];
        int c = 0;
        
        int i = 0;
        for(i = 2; i < cost.size(); i++)
        {
            c = cost[i] + min(a, b);
            a = b;
            b = c;
        }
        
        return min(a, b);
    }
};