// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> m;
        unordered_map<int, int> m2;
        
        if(trust.empty())
            return n;
        
        for(int i = 0; i < trust.size(); i++)
        {            
            m[trust[i][1]]++;
            m2[trust[i][0]]++;
        }
        
        for(auto i : m)
            if(i.second == n - 1)
                if(m2.find(i.first) == m2.end())
                    return i.first;
        
        return -1;
    }
};