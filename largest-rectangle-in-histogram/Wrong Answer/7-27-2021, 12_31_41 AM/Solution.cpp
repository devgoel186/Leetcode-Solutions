// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(0);
        int n = heights.size();
        int max = 0, i = 0;
        int t, areaTop;
        
        while(i < n)
        {
            if(s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i);
                i++;
            }
            else
            {
                t = s.top();
                s.pop();
                
                if(s.empty())
                    areaTop = heights[t] * i;
                else
                    areaTop = heights[t] * (i - s.top() - 1);
                
                if(max < areaTop)
                    max = areaTop;
            }
        }
        
//         while(!s.empty())
//         {
//             t = s.top();
//             s.pop();
//             if(s.empty())
//                 areaTop = heights[t] * i;
//             else
//                 areaTop = heights[t] * (i - s.top() - 1);
            
//             if(max < areaTop)
//                 max = areaTop;
//         }
        return max;
    }
};