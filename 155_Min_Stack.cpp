//155. Min Stack
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (minS.empty()) minS.push(make_pair(x, x));
        else minS.push(make_pair(x, min(x, minS.top().second)));
    }
    
    void pop() {
        minS.pop();
    }
    
    int top() {
        return minS.top().first;
    }
    
    int getMin() {
        return minS.top().second;
    }
private:
    stack<pair<int, int>> minS;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */