// https://leetcode.com/problems/car-fleet

class Solution {
public:
    // bool check(int a, int b, int s1, int s2, int target)
    // {
    //     int x = a;
    //     int y = b;
    //     while((x + s1 <= target) && (y + s2 <= target))
    //     {
    //         if((x + s1) == (y + s2))
    //             return true;
    //         x = x + s1;
    //         y = y + s2;
    //     }
    //     return false;
    // }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> ps;
        
        for(int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            ps.push_back({position[i], time});
        }
        
        sort(ps.begin(), ps.end());
        
        int fleets = 1;
        for(int i = n - 1; i >= 1; i--)
        {
            if(ps[i - 1].second <= ps[i].second)
                ps[i - 1].second = ps[i].second;
            else
                fleets++;
        }
        
        return fleets;
    }
};