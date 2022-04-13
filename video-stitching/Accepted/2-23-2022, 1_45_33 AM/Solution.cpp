// https://leetcode.com/problems/video-stitching

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        
        int start = 0, end = 0, count = 0;
        for(int i = 0; start < time;)
        {
            while(i < clips.size() && clips[i][0] <= start)
            {
                end = max(end, clips[i][1]);
                i++;
            }
            
            if(start == end)
                return -1;
            
            start = end;
            count++;
        }
        
        return count;
    }
};