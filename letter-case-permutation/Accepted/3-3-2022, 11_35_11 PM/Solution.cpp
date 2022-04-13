// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    void helper(string ans, vector<string> &res, string s, int i)
    {
        if(i == s.length())
        {
            res.push_back(ans);
            return;
        }
        
        if(!(s[i] >= '0' && s[i] <= '9'))
        {
            helper(ans + (char)toupper(s[i]), res, s, i + 1);
            helper(ans + (char)tolower(s[i]), res, s, i + 1);
        }
        else
            helper(ans + s[i], res, s, i + 1);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        helper("", res, s, 0);
        
        return res;
    }
};