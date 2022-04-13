// https://leetcode.com/problems/all-possible-full-binary-trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ans;
        
        if(N < 1 || N % 2 == 0) {
            return ans;
        }
        
        if(N == 1)
        {
            TreeNode *newRoot = new TreeNode(0);
            return {newRoot};
        }
        
        for(int k = 2; k < N; k += 2) {
            vector<TreeNode*> v1 = allPossibleFBT(k - 1);
            vector<TreeNode*> v2 = allPossibleFBT(N - k);
            
            for(auto i : v1) {
                for(auto j : v2) {
                    TreeNode* newRoot = new TreeNode(0);
                    newRoot->left = i;
                    newRoot->right = j;
                    ans.push_back(newRoot);
                }
            }
        }
        
        return ans;
    }
};