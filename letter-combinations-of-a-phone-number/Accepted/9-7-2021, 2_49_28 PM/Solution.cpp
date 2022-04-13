// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> num = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void calc(string digits, vector<string> &res, string curr)
    {
        if(digits == "")
        {
            if(curr != "")
                res.push_back(curr);
            return;
        }
        
        char x = digits[0] - '0';
        for(int i = 0; i < 3; i++)
            calc(digits.substr(1, digits.size() - 1), res, curr + num[x - 1][i]);
        
        if(x == 7 || x == 9)
            calc(digits.substr(1, digits.size() - 1), res, curr + num[x - 1][3]);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        calc(digits, res, "");
        return res;
    }
};