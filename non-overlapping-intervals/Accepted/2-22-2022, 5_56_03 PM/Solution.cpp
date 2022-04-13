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
                end = min(end, i[1]);
            }
            else
                end = i[1];
        }
        
        return count;
    }
};