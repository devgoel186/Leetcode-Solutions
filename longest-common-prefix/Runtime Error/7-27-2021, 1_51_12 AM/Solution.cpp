// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool condition = false;
        int index = 0;
        string compare = "";
        while(!condition)
        {    
            compare += strs[0][index];
            for(int i = 1; i < strs.size(); i++)
            {                
                if(strs[i][index] != compare[index])
                {
                    condition = true;
                    break;
                }
            }
            index++;
        }
        return compare.substr(0, compare.length() - 1);
    }
};