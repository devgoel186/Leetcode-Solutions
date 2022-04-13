// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for(auto i : s)
        {
            sum *= 26;
            sum += i - 'A' + 1;
        }
        
        return sum;
    }
};