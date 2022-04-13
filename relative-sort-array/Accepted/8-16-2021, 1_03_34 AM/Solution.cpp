// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for(auto i : arr1)
            m[i]++;
        
        int index = 0;
        
        for(auto i : arr2)
        {
            while(m[i]-- > 0)
                arr1[index++] = i;
        }
        
        for(auto j : m)
        {
            while(j.second-- > 0)
                arr1[index++] = j.first;
        }
        
        return arr1;
    }
};