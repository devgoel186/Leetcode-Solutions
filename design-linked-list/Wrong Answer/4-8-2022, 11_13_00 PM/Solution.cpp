// https://leetcode.com/problems/design-linked-list

class Node {
public:
    int val;
    Node *next;
    
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class MyLinkedList {
public:    
    Node *head;
    
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        Node *temp = head;
        
        while(temp != NULL && index--)
            temp = temp->next;
        
        if(temp == NULL)
            return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node *temp = head;
        
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;
        
        if(temp == NULL)
            return;
        
        temp->next = new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        Node *temp = head;
        index--;
        
        while(temp != NULL && index > 0)
            temp = temp->next;
        
        if(temp == NULL)
            return;
        
        Node *newNode = new Node(val);
        Node *tempNext = temp->next;
        temp->next = newNode;
        newNode->next = tempNext;
    }
    
    void deleteAtIndex(int index) {
        if(head == NULL)
            return;
        
        if(index == 1)
        {
            head = head->next;
            return;
        }
        
        Node *prev = head;
        Node *temp = head;
        index--;
        
        while(temp != NULL && index--)
        {
            prev = temp;
            temp = temp->next;
        }
        
        if(temp == NULL)
            return;
        
        Node *tempNext = temp->next;
        prev->next = tempNext;
        temp->next = NULL;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */