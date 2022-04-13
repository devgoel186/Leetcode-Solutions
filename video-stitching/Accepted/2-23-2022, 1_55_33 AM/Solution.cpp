// https://leetcode.com/problems/video-stitching

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        
        int start = 0, end = 0, count = 0;
        
        while(end < time)
        {               
            for(int i = 0; i < clips.size(); i++)
            {
                int l = clips[i][0];
                int r = clips[i][1];
                
                if(l <= start)
                    end = max(r, end);
                else
                    break;
            }
            
            if(start == end)
                return -1;
            
            start = end;
            count++;
        }
        
        return count;
    }
};