// https://leetcode.com/problems/kth-distinct-string-in-an-array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        
        for(auto i : arr)
            m[i]++;
        
        for(auto i : arr)
        {
            if(m[i] == 1 && --k == 0)
                return i;
        }
        
        return "";
    }
};