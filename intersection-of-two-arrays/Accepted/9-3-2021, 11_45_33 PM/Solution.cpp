// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        
        for(auto i : nums1)
            m[i] = 1;
        
        for(auto i : nums2)
            if(m.find(i) != m.end())
                m[i] = 2;
        
        vector<int> ans;
        for(auto i : m)
        {
            if(i.second == 2)
                ans.push_back(i.first);
        }
        
        return ans;
    }
};