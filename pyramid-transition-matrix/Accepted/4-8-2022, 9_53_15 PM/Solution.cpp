// https://leetcode.com/problems/pyramid-transition-matrix

class Solution {
public:
    unordered_set<string> fails;  // for storing the layer which fails, i.e., no possible 
                                  // set of pyramid originates from there
    bool helper(string bottom, unordered_map<string, vector<char>> m, string layer, int start)
    {
        if(bottom.size() == 1)
            return true;
        
        if(fails.find(bottom) != fails.end())
            return false;
        
        if(start == bottom.size() - 1)
            return helper(layer, m, "", 0);
        
        string base = bottom.substr(start, 2);
        for(auto i : m[base])
        {
            if(helper(bottom, m, layer + i, start + 1))
                return true;
        }
        
        fails.insert(bottom);
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        
        for(auto i : allowed)
        {
            string base = i.substr(0, 2);
            m[base].push_back(i[2]);
        }
        
        return helper(bottom, m, "", 0);
    }
};