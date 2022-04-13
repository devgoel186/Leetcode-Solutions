// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();      
        int total = 0, curr = 0, index = 0;
        for(int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if(curr < 0)
            {
                curr = 0;
                index = i + 1;
            }
        }
        
        if(total < 0)
            return -1;
        return index;
    }
};