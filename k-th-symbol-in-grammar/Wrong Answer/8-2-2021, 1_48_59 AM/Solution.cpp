// https://leetcode.com/problems/k-th-symbol-in-grammar

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1)
            return 0;
        if(k <= (1 << n - 2))
            return kthGrammar(n - 1, k);
        return !kthGrammar(n - 1, (1 << (n - 1)) - k);
    }
};