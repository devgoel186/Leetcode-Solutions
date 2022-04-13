// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        
        for(auto i : text)
            m[i]++;
        
        return min({m['b'], m['a'], m['l'] / 2, m['o'] / 2, m['n']});
    }
};