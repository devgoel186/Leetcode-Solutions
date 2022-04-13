// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int m = INT_MIN;
        for(auto i : n)
            if(i - '0' > m)
                m = i - '0';
        
        return m;
    }
};