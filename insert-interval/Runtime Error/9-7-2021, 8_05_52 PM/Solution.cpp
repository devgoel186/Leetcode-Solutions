// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> mergedInterval;
        
        vector<vector<int>> res;
        if(intervals.size() == 0)
            return {newInterval};
        
        int i;
        for(i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][1] < newInterval[0])
                res.push_back(intervals[i]);
            else
                break;
        }
        
        int minEnd = min(newInterval[0], intervals[i][0]);
        int maxEnd = newInterval[1];
        for(; i < intervals.size(); i++)
        {                        
            if(intervals[i][1] > newInterval[1])
            {
                if(newInterval[1] >= intervals[i][0])
                {
                    maxEnd = intervals[i][1];
                    i++;
                }
                // else
                // {
                //     maxEnd = newInterval[1];
                //     i++;
                // }
                break;
            }
        }
        
        res.push_back({minEnd, maxEnd});
        
        for(; i < intervals.size(); i++)
        {
            res.push_back(intervals[i]);
        }
        
        return res;
    }
};