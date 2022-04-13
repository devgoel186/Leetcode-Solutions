// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> s1;
        unordered_set<string> res;
        
        for(int i = 0; i < s.length() - 10; i++)
        {
            string temp = s.substr(i, 10);
            if(s1.find(temp) != s1.end())
                res.insert(temp);
            else
                s1.insert(temp);
        }
        
        vector<string> ans(res.begin(), res.end());
        
        return ans;
    }
};