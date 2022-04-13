// https://leetcode.com/problems/h-index-ii

class Solution {
public:
    int helper(vector<int> &citations, int l, int r)
    {
        if(l > r)
            return -1;
        
        int mid = (l + r) / 2;
        
        if(citations[mid] == mid + 1)
            return mid + 1;
        
        else if(citations[mid] > mid)
            return helper(citations, mid + 1, r);
        
        return helper(citations, l, mid - 1);
    }
    
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1)
        {
            if(citations[0] == 1)
                return 1;
            return 0;
        }
        
        return helper(citations, 0, citations.size() - 1);
    }
};