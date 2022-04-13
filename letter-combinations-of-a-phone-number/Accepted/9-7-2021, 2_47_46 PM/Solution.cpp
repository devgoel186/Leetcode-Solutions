// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> num = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void calc(string digits, vector<string> &res, string curr)
    {
        if(digits == "")
        {
            if(curr == "")
                return;
            res.push_back(curr);
            return;
        }
        
        char x = digits[0] - '0';
        
        // calc(digits.substr(0, digits.size() - 1), res, curr);
        calc(digits.substr(1, digits.size() - 1), res, curr + num[x - 1][0]);
        calc(digits.substr(1, digits.size() - 1), res, curr + num[x - 1][1]);
        calc(digits.substr(1, digits.size() - 1), res, curr + num[x - 1][2]);
        
        if(x == 7 || x == 9)
            calc(digits.substr(1, digits.size() - 1), res, curr + num[x - 1][3]);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        calc(digits, res, "");
        return res;
    }
};