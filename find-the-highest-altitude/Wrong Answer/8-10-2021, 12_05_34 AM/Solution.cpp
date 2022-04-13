// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        if(gain.size() == 0)
            return 0;
        int max = 0;
        for(int i = 1; i < gain.size(); i++)
        {
            gain[i] += gain[i - 1];
            if(gain[i] > max)
                max = gain[i];
        }
        return max;
    }
};