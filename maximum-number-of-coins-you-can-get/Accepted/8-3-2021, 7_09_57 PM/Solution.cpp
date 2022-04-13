// https://leetcode.com/problems/maximum-number-of-coins-you-can-get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int n = piles.size() / 3;
        int sum = 0;
        for(int i = 1; i < 2 * n; i += 2)
        {
            sum += piles[i];
        }
        return sum;
    }
};