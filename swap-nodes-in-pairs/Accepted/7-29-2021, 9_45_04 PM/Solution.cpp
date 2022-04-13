// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head, *next = NULL, *prev = NULL;
        while(curr != NULL && curr->next != NULL)
        {
            next = curr->next;
            curr->next = next->next;
            next->next = curr;
            if(prev == NULL)
            {
                head = next;
                prev = curr;
            }
            else
            {
                prev->next = next;
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};