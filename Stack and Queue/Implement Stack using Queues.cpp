//https://leetcode.com/problems/implement-stack-using-queues/

    queue<int> q;
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
       int f= q.front();
        q.pop();
        return f;
    }
    
    /** Get the top element. */
    int top() {
       return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }


