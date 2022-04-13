// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *temp = l1;
        ListNode *temp2 = l2;
        while(temp != NULL && temp2 != NULL)
        {
            if(carry == 1)
                temp->val = temp->val + temp2->val + 1;
            else
                temp->val = temp->val + temp2->val;
            
            if(temp->val > 9)
            {
                temp->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            temp = temp->next;
            temp2 = temp2->next;
            
        }
        
        while(temp != NULL)
        {
            if(carry == 1)
                temp->val = temp->val + 1;
            
            if(temp->val > 9)
            {
                temp->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            
            if(temp->next == NULL && carry > 0)
            {
                temp->next = new ListNode(1);
                break;
            }
            
            temp = temp->next;
        }
        
        while(temp2 != NULL)
        {
            if(carry == 1)
            {
                temp = new ListNode(temp2->val + 1);
            }
            else
                temp = new ListNode(temp2->val);
            
            if(temp2->val > 9)
            {
                temp->val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            
            if(temp2->next == NULL && carry > 0)
            {
                temp->next = new ListNode(1);
                break;
            }
            
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return l1;
    }
};