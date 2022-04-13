// https://leetcode.com/problems/linked-list-random-node

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
    ListNode *x;
    Solution(ListNode* head) {
       x = head;
    }
    
    int getRandom() {
        int len = 0;
        ListNode *temp = x;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        
        int n = rand() % len + 1;
        temp = x;
        
        while(--n)
            temp = temp->next;
        
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */