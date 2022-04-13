// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;

        int i = 0;
        for (i = 0; i < n - 1; i++)
        {
            int start1 = intervals[i][0];
            int end1 = intervals[i][1];

            while (i < n - 1 && end1 >= intervals[i + 1][0] && end1 < intervals[i+1][1])
            {
                end1 = intervals[i + 1][1];
                i++;
            }

            res.push_back({start1, end1});
        }

        if (i == n - 1)
            res.push_back({intervals[n - 1][0], intervals[n - 1][1]});
        return res;
    }
};