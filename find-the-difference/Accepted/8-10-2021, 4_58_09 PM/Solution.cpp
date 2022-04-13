// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorSum = 0, i;
        for(i = 0; i < s.length(); i++)
        {
            xorSum ^= t[i] ^ s[i];
        }
        xorSum ^= t[i];
        return (char)xorSum;
    }
};