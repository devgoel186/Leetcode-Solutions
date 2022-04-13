// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n = height.size();
        int res = 0;
        int i = 0;
        while(i < n)
        {
            if(s.empty() || (height[i] < height[s.top()]))
            {
                s.push(i);
                i++;
            }
            else
            {
                int t = s.top();
                s.pop();                
                
                if(s.empty())
                    continue;
                
                res += (min(height[s.top()], height[i]) - height[t]) * (i - s.top() - 1);
            }
        }
        
//         while(!s.empty())
//         {
//             int t = s.top();
//             s.pop();

//             if(s.empty())
//                 break;

//             res += (min(height[s.top()], height[i]) - height[t]) * (i - s.top() - 1);
//         }
        
        return res;
    }
};