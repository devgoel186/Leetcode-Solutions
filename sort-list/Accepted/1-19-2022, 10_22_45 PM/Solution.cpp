// https://leetcode.com/problems/sort-list

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
    ListNode *makeList(vector<int> &order)
    {
        if(order.size() == 0)
            return NULL;
        
        ListNode *x = new ListNode();
        ListNode *temp = x;
        temp->val = order[0];
        
        for(int i = 1; i < order.size(); i++)
        {
            temp->next = new ListNode(order[i]);
            temp = temp->next;
        }
        
        return x;
    }
    
    void traverse(ListNode *head, vector<int> &order)
    {
        ListNode *temp = head;
        while(temp != NULL)
        {
            order.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        vector<int> order;
        traverse(head, order);
        sort(order.begin(), order.end());
        ListNode *newHead = makeList(order);
        
        return newHead;
    }
};