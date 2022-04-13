// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int end = INT_MIN, count = 0;
        for(auto i : intervals)
        { 
            if(i[0] < end)
            {
                count++;
                end = min(end, i[0]);
            }
            else
                end = i[0];
        }
        
        return count;
    }
};