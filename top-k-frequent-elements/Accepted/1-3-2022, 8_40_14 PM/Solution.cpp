// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> pqmax;
        for(auto i : nums)
            m[i]++;
        
        for(auto &i : m)
        {
            pqmax.push(i.second);
            while(pqmax.size() > k)
                pqmax.pop();
        }
        
        vector<int> res;
        
        for(auto &i : m)
        {
            if(i.second >= pqmax.top())
                res.push_back(i.first);
        }
        
        return res;
    }
};