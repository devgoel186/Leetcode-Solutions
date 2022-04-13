// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0, i = 0;
        
        while(i < height.size())
        {
            if(s.empty() || (height[i] < height[s.top()]))
            {
                s.push(i++);
            }
            
            else
            {
                int x = s.top();
                s.pop();
                if(s.empty())
                    continue;
                
                res += (min(height[s.top()], height[i]) - height[x]) * (i - s.top() - 1);
            }
        }        
        
        return res;
    }
};

