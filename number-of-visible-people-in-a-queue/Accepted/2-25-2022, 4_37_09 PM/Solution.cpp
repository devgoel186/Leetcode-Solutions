// https://leetcode.com/problems/number-of-visible-people-in-a-queue

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        
        stack<int> s;
        s.push(heights[n - 1]);
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(s.empty() || (s.top() >= heights[i]))
            {
                s.push(heights[i]);
                ans[i] = 1;
            }
            
            else
            {
                int count = 0;
                while(!s.empty() && (s.top() < heights[i]))
                {
                    s.pop();
                    count++;
                }
                if(!s.empty())
                    count++;
                
                s.push(heights[i]);
                ans[i] += count;
            }
        }
        
        return ans;
    }
};