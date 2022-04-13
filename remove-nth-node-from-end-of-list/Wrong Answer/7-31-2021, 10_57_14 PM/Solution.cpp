// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int count = 0;
        int length = 0;
        
        if(n == 1)
        {
            ListNode *store = head;
            head = head->next;
            delete store;
            return head;
        }
        
        while(temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        temp = head;
        
        while(temp != NULL)
        {
            count++;
            if(count == length - n)
            {
                ListNode *store = temp->next;
                temp->next = temp->next->next;
                delete store;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};