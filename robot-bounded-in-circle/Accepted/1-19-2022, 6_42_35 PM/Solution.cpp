// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    void move(int &x, int &y, int &dir, char ch)
    {
        if(ch == 'L')
            dir = (dir + 3) % 4;
        else if(ch == 'R')
            dir = (dir + 1) % 4;
        else
        {
            if(dir == 0)
                y++;
            else if(dir == 1)
                x++;
            else if(dir == 2)
                y--;
            else if(dir == 3)
                x--;
        }
    }
    
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        for(int i = 0; i < instructions.size(); i++)
            move(x, y, dir, instructions[i]);
        
        if(x == 0 && y == 0)
            return true;
        if(dir != 0)
            return true;
        return false;
    }
};