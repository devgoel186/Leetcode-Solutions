// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int curr = 0;
        int pos = 0;
        
        for(int i = 0; i < gas.size(); i++)
        {
            tank += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            
            if(curr < 0)
            {
                curr = 0;
                pos = i + 1;
            }
        }
        
        if(tank < 0)
            return -1;
        return pos;
    }
};