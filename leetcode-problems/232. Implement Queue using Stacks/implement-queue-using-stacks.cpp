/**
 * File: implement-queue-using-stacks.cpp * https://leetcode.com/problems/implement%20queue%20using%20stacks/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class MyQueue {
public:
    stack<int> s;
    
    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x){
        if(s.size()==0){
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        pushHelper(x);
        s.push(data);
        return;
        
    }

    // Removes the element from in front of queue.
    int pop(void) {
        int t = s.top();
        s.pop();
        return t;
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */