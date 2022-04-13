// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        
        for(int j = 1; j < n; j++)
        {
            int llarge = 0, lsmall = 0;
            int rlarge = 0, rsmall = 0;
            
            for(int i = 0; i < j; i++)
            {
                if(rating[i] < rating[j])
                    lsmall++;
                else
                    llarge++;
            }
            
            for(int k = j + 1; k < n; k++)
            {
                if(rating[k] < rating[j])
                    rsmall++;
                else
                    rlarge++;
            }
            
            count += lsmall * rlarge + llarge * rsmall;
        }
        
        return count;
    }
};