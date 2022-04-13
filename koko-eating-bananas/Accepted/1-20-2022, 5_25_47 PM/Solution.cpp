// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool possible(vector<int> &piles, int rate, int h)
    {
        int time = 0;
        for(int i : piles)
        {
            time += i / rate;
            if(i % rate != 0)
                time++;
        }
        
        if(time <= h)
            return true;
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MAX;
        
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(possible(piles, mid, h))
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return l;
    }
};