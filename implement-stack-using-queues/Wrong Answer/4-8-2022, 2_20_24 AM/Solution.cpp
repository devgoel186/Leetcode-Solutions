// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty())
        {
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty())
            return -1;
        
        int x = q1.front();
        q1.pop();
        
        while(!q2.empty())
        {
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */