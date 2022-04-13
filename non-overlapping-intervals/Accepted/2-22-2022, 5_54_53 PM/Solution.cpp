// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int end = INT_MIN, count = 0;
        for(auto i : intervals)
        {
            int n_start = i[0];
            int n_end = i[1];
            
            if(n_start < end)
            {
                count++;
                end = min(end, n_end);
            }
            else
                end = n_end;
        }
        
        return count;
    }
};