// https://leetcode.com/problems/longest-uncommon-subsequence-i

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b)
            return -1;
        else
        {
            return max(a.length(), b.length());
//             if(a.length() > b.length())
//             {
//                 if(a.substr(0, b.length()) == b)
//                     return -1;
//                 else
//                     return b.length();
//             }
            
//             else if(b.length() > a.length())
//             {
//                 if(b.substr(0, a.length()) == a)
//                     return -1;
//                 else
//                     return a.length();
//             }
            
//             else
//                 return a.length();
        }
    }
};