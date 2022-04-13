// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        
        int i = 0;
        int res = 0;
        
        while(i < height.size())
        {
            if(s.empty() || height[i] < height[s.top()])
            {
                s.push(i);
                i++;
            }
            
            else
            {
                int x = s.top();
                s.pop();

                if(s.empty())
                    continue;

                res += (min(height[i], height[s.top()]) - height[x]) * (i - s.top() - 1);
            }
        }
        
        return res;
    }
};