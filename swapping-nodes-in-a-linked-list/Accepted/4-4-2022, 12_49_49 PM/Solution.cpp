// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
class Solution {
public:
    int length(ListNode *head)
    {
        int count = 0;
        
        ListNode *temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int len = length(head);
        
        ListNode *x = NULL;
        ListNode *y = NULL;
        ListNode *temp = head;
        int count = 0;
        
        while(temp != NULL && count <= len)
        {
            count++;
            
            if(count == k)
                x = temp;
            
            if(count == len - k + 1)
                y = temp;
            
            temp = temp->next;
        }
        
        swap(x->val, y->val);
        
        return head;
    }
};