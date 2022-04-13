// https://leetcode.com/problems/filling-bookcase-shelves

class Solution {
public:
    int helper(vector<vector<int>> &books, int i, int mr, int rem, int shelfWidth)
    {
        if(i == books.size() - 1)
        {
            if(books[i][0] > rem)
                return books[i][1];
            return max(mr, books[i][1]);
        }
        
        if(books[i][0] > rem)
            return mr + helper(books, i + 1, books[i][1], shelfWidth - books[i][0], shelfWidth);
        
        int ans = 0;
        ans = min(helper(books, i + 1, max(mr, books[i][1]), rem - books[i][0], shelfWidth), mr + helper(books, i + 1, books[i][1], shelfWidth - books[i][0], shelfWidth));
        
        return ans;
    }
    
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
        return helper(books, 0, 0, shelfWidth, shelfWidth);
    }
};