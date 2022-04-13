// https://leetcode.com/problems/defanging-an-ip-address

class Solution {
public:
    string defangIPaddr(string address) {
        int i = 0;
        string ans = "";
        
        while(i != address.length())
        {
            if(address[i] != '.')
                ans += address[i];
            else
                ans += "[.]";
            i++;
        }
        
        return ans;
    }
};