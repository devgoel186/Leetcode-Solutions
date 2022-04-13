// https://leetcode.com/problems/car-fleet

class Solution {
public:
    bool check(int a, int b, int s1, int s2, int target)
    {
        int x = a;
        int y = b;
        while((x + s1 <= target) && (y + s2 <= target))
        {
            if((x + s1) == (y + s2))
                return true;
            x = x + s1;
            y = y + s2;
        }
        return false;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map<int, int> m;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            bool flag = false;
            for(int j = i + 1; j < n; j++)   
            {
                if(check(position[i], position[j], speed[i], speed[j], target))
                {
                    m[position[i]]++;
                    m[position[j]]++;
                    flag = true;
                }
            }
            if(flag)
                count++;
        }
        
        for(int i = 0 ; i < n; i++)
        {
            if(m.find(position[i]) == m.end())
                count++;
        }
        
        return count;
    }
};