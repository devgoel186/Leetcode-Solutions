// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<int> detection(26, 0);
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for(auto i : strs)
        {
            string key = i;
            sort(key.begin(), key.end());
            m[key].push_back(i);
        }
        
        for(auto i : m)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};