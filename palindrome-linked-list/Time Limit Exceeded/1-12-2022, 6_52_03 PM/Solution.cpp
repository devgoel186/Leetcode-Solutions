// https://leetcode.com/problems/palindrome-linked-list

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
    string reverse(ListNode *head) 
    {
        if(head == NULL)
            return "";
        
        string s = "";
        char ch = head->val + '0';
        s = reverse(head->next) + ch;
        return s;
    }
    
    string forward(ListNode *head)
    {
        if(head == NULL)
            return "";
        
        string s = "";
        char ch = head->val + '0';
        s = ch + forward(head->next);
        return s;
    }
    
    bool isPalindrome(ListNode* head) {
        return forward(head) == reverse(head);
    }
};