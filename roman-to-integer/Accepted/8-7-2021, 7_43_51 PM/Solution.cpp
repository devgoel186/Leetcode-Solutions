// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        // populate map (brute force)
        unordered_map<char, int> mp = {
            { 'I' , 1 },
            { 'V' , 5 },
            { 'X' , 10 },
            { 'L' , 50 },
            { 'C' , 100 },
            { 'D' , 500 },
            { 'M' , 1000 }};
        
        int num=0;
        
        for(size_t i=0; i<s.length(); ++i){
            
            if( mp[s[i]] < mp[s[i+1]] )
                num -= mp[s[i]];
            else 
                num += mp[s[i]];
        }
        return num;
    }
};