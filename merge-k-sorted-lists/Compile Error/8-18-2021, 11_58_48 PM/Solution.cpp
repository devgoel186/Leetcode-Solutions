// https://leetcode.com/problems/merge-k-sorted-lists

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
    struct compare
    {
        bool operator()(const ListNode *l, const ListNode *r)
            return l->val > r->val;
    };
    
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        
        for(auto i : lists)
        {
            if(i != NULL)
                pq.push(i);
        }
        
        if(pq.empty())
            return NULL;
        
        ListNode* x = pq.top();
        pq.pop();
        if(x->next != NULL)
            pq.push(x->next);
                
        ListNode *tail = x;
        while(!pq.empty())
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            
            if(tail->next != NULL)
                pq.push(tail->next);
        }
        
        return x;
    }
};