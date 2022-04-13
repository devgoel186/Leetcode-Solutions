// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i = 0; i < queries.size(); i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];            
            int count = 0;
            for(int j = 0; j < points.size(); j++)
            {
                int x1 = points[j][0];
                int y1 = points[j][1];
                int distance = (int)pow((x - x1), 2) + (int)pow((y - y1), 2);
                if(distance <= r*r)
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};