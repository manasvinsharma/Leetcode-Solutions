class MyQueue {
public:
    stack<int>s1,s2;
    int front;
    
    MyQueue() {
        front = -1;
    }
    
    void push(int x) {
        if(s1.empty())
        {
            s1.push(x);
            front = x;
        }
        else
        {
            s1.push(x);
        }
    }
    
    int pop() {
        int ans;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        ans = s2.top();
        s2.pop();
        
        if(!s2.empty())
            front = s2.top();
        
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        return ans;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */