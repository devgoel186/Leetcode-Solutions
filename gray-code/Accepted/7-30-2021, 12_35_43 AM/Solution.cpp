// https://leetcode.com/problems/gray-code

class Solution {
public:
    int grayCodeCalculator(int n)
    {
        return n ^ (n >> 1);
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < (1 << n); i++)
        {
            res.push_back(grayCodeCalculator(i));
        }
        return res;
    }
};