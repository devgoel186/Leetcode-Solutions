// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void helper(vector<string> &res, string digits, string ans, int index)
    {
        if(index == digits.size())
        {
            res.push_back(ans);
            return;
        }
        
        int x = digits[index] - '0' - 2;
        for(auto i : m[x])
            helper(res, digits, ans + i, index + 1);
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        
        vector<string> res;
        helper(res, digits, "", 0);
        
        return res;
    }
};