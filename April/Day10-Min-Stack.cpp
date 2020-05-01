/*
** Min Stack **

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

/*
I guess there are two interpretation for this question, 
using STL stack to implement min-stack or implementing min-stack without STL stack

** Analysis of Algorithm:
n - the number of input
Time Complexity: O(1)
Space Complexity: O(n)
*/
class MinStack {
private:
    vector<int> data;
    priority_queue <int, vector<int>, greater<int> > min;// indeed is a min heap
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);
        if (min.empty() || x <= min.top()) min.push(x);
    }
    
    void pop() {
        if (data.empty()) return;
        if (data.back() == min.top()) min.pop();
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
private:
    stack<int> data;
    stack<int> min;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if (min.empty() || x <= min.top()) min.push(x);
    }
    
    void pop() {
        if (data.empty()) return;
        if (data.top() == min.top()) min.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */