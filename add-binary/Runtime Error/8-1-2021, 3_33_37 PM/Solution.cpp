// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int x = 0, y = 0;
        int index = 0;
        for(int i = a.length() - 1; i >= 0; i--)
        {
            x = x + (a[i] - '0') * (1 << index);
            index++;
        }
        index = 0;
        for(int i = b.length() - 1; i >= 0; i--)
        {
            y = y + (b[i] - '0') * (1 << index);
            index++;
        }
        
        cout << x << " " << y;
        
        int z = x + y;
        string res;
        if(z == 0)
            return "0";
        
        while(z != 0)
        {
            char digit = (z & 1) ? '1' : '0';
            res = digit + res;
            z >>= 1;
        }
        return res;
    }
};