// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildTree(vector<int> inorder, int l, int r)
    {
        if(l > r)
            return NULL;
        
        int mid = (l + r) / 2;
        
        TreeNode *root = NULL;
        
        root = new TreeNode(inorder[mid]);
        root->left = buildTree(inorder, l, mid - 1);
        root->right = buildTree(inorder, mid + 1, r);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *temp = head;
        vector<int> inorder;
        while(temp != NULL)
        {
            inorder.push_back(temp->val);
            temp = temp->next;
        }
        
        TreeNode *root = buildTree(inorder, 0, inorder.size()  -1);
        return root;
    }
};