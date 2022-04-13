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
        ListNode* list = NULL;         // Used to iterate through linked list
        ListNode* res = NULL;          // Pointer to beginning of list 
        int carry = 0;                     // Carry over between nodes
        
        while (l1 != NULL && l2 != NULL) {
            
            if (list == NULL) {
                list = new ListNode(carry);
            }
            
            else {
                list->next = new ListNode(carry);
                list = list->next;
            }
            
            if (res == NULL) {
                res = list;
            }
            
            carry = (list->val + (l1->val + l2->val)) / 10;
            list->val = (list->val + (l1->val + l2->val)) % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL) {
            list->next = new ListNode(carry);
            list = list->next;
            carry = (list->val + l1->val)/10;
            list->val = (list->val + l1->val)%10;       
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            list->next = new ListNode(carry);
            list = list->next;
            carry = (carry + l2->val)/10;
            list->val = (list->val + l2->val)%10;       
            l2 = l2->next;
        }

        while (carry != 0) {
            list->next = new ListNode(carry%10);
            list = list->next;
            carry = carry/10;
        }
        
        return res;
    }
};