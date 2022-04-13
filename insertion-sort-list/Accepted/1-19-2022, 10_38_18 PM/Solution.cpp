// https://leetcode.com/problems/insertion-sort-list

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
    void insertionSort(vector<int> &arr)
    {
        for(int i = 1; i < arr.size(); i++)
        {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
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
    
    ListNode* insertionSortList(ListNode* head) {
        vector<int> order;
        traverse(head, order);
        insertionSort(order);
        ListNode *newHead = makeList(order);
        
        return newHead;
    }
};