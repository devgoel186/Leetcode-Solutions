// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int j = 0, count = 0;
        for(int i = 0; i < text1.length() && j < text2.length(); i++)
        {
            if(text1[i] == text2[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};