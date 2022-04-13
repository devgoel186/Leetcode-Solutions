// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    void generateParenthesisHelper(vector<string> &a, int o, int c, string res) {
        if(o == 0 && c == 0)
            a.push_back(res);
        if(c > 0)
            generateParenthesisHelper(a, o, c - 1, res + ")");
        if(o > 0)
            generateParenthesisHelper(a, o - 1, c + 1, res + "(");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisHelper(ans, n, 0, "");
        return ans;
    }
};