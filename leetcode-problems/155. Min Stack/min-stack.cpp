/**
 * File: min-stack.cpp * https://leetcode.com/problems/min%20stack/
 * By zuimrs
 * Runtime:  29 ms
 * Language: cpp
 */

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
        int t = s1.top();
	    return t;
    }
    int getMin() {
	    return s2.top();
    }
};