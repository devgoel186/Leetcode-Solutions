// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto i : ops)
        {
            if(i == "+")
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                int z = x + y;
                s.push(y);
                s.push(x);
                s.push(z);
            }
            
            else if(i == "D")
            {
                int x = s.top();
                int z = 2 * x;
                s.push(z);
            }
            
            else if(i == "C")
                s.pop();
            
            else
                s.push(stoi(i));
        }
        
        int sum = 0;
        while(!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};