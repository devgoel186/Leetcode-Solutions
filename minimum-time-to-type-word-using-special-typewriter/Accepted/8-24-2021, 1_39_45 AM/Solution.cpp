// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter

class Solution {
public:
    int minTimeToType(string w) {
        int res = min(w[0] - 'a', 26 - (w[0] - 'a'));
        
        for (int i = 1; i < w.size(); i++)
            res += min(abs(w[i] - w[i - 1]), 26 - abs(w[i] - w[i - 1]));
        
        return res + w.size();
    }
};