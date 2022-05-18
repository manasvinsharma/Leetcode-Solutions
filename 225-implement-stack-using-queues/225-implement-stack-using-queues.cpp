class MyStack {
public:
    queue<int>q;
    int topp;
    
    MyStack() {
        topp=-1;
    }
    
    void push(int x) {
        q.push(x);
        topp = x;
    }
    
    int pop() {
        int n = q.size();
        
        for(int i=1;i<=n-1;i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            
            if(i==n-1)
                topp = temp;
        }
        
        int ans = q.front();
        q.pop();
        
        return ans;
    }
    
    int top() {
        return topp;
    }
    
    bool empty() {
        return q.empty();
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