// https://leetcode.com/problems/maximum-product-subarray

class Solution {
    public:
    int maxProduct(vector<int>& A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if(l == 0)
                l = A[i];
            else
                l *= A[i];
            
            if(r == 0)
                r = A[i];
            else
                r *= A[i];
            
            res = max({l , r, res});
        }
        
        return res;
    }
};