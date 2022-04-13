// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0, n = heights.size(), max = 0, globalMax = 0;
        stack<int> s;
        while(i < n)
        {
            if(s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i);
                i++;
            }
            
            else
            {
                int x = s.top();
                s.pop();
                
                if(s.empty())
                    max = heights[x] * i;
                else
                    max = heights[x] * (i - s.top() - 1);
                
                if(max > globalMax)
                    globalMax = max;
            }
        }
        
        while(!s.empty())
        {
            int x = s.top();
            s.pop();
                
            if(s.empty())
                max = heights[x] * i;
            else
            {
                max = heights[x] * (i - s.top() - 1);
            }

            if(max > globalMax)
                globalMax = max;
        }
        
        return globalMax;
    }
};