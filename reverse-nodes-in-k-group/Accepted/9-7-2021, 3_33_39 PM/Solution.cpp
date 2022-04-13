// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverse(ListNode *head, ListNode *node)
    {
        if(head == NULL)
            return NULL;
        
        ListNode *next = NULL, *curr = head, *prev = NULL;
        
        while(curr != node)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;            
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        
        ListNode *node = head;
        for(int i = 0; i < k; i++)
        {
            if(node == NULL)
                return head;
            node = node->next;
        }
        
        ListNode *x = reverse(head, node);
        head->next = reverseKGroup(node, k);
        
        return x;
    }
};