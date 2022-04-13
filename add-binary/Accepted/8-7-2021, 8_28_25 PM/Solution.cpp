// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        string res = "";
        int carry = 0;
        while(i >= 0 && j >= 0)
        {
            char digit;
            if(a[i] == '1' && b[j] == '1')
            {
                digit = carry + '0';
                carry = 1;
            }
            else if(a[i] == '0' && b[j] == '0')
            {
                digit = carry + '0';
                carry = 0;
            }
            else if(a[i] == '0' || b[j] == '0')
                digit = '1' - carry;
            res = digit + res;
            i--;
            j--;
        }
        
        while(i >= 0)
        {
            char digit;
            if(a[i] == '1')
                digit = '1' - carry;
            else
            {
                digit = carry + '0';
                carry = 0;
            }        
            res = digit + res;
            i--;
        }
        
        while(j >= 0)
        {
            char digit;
            if(b[j] == '1')
                digit = '1' - carry;
            else
            {
                digit = carry + '0';
                carry = 0;
            }        
            res = digit + res;
            j--;
        }
        
        if(carry == 1)
            res = '1' + res;
        
        return res;
    }
};