// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        
        for(auto i : nums)
        {
            s.insert(i);
            if(s.size() > 3)
                s.erase(*(s.begin()));
        }
        
        if(s.size() == 3)
            return *(s.begin());
        return *(s.end());
    }
};