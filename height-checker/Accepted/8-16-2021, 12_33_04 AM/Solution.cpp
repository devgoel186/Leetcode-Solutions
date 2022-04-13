// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0, pos = 1;
        vector<int> map(101,0);
        for(int ele: heights) map[ele]++;
        for(int height: heights) {
            while(map[pos] == 0) pos++;
            if(pos != height) count++;
            map[pos]--;
        }
        return count;
    }
};