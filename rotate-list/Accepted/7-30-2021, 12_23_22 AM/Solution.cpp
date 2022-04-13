// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {        
        if(head == NULL)
            return NULL;
        ListNode *temp = head;
        int length = 0;
        while(temp->next != NULL)
        {
            length++;
            temp = temp->next;
        }
        length++;
        ListNode *tail = temp;
        
        temp = head;
        ListNode *prev = NULL;
        int count = 0;
        k = k % length;
        while(count != length - k - 1)
        {
            count++;
            temp = temp->next;
        }
        
        if(temp == NULL)
            return head;
        else
        {
            tail->next = head;
            head = temp->next;
            temp->next = NULL;
        }
        
        return head;
    }
};