#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-a-stack-with-increment-operation/
/**
 * just implement a standard stack and for the inc operation use a auxiliary stack for incrementing k values
 */
class CustomStack {
public:
    stack<int> st;
    int maxSize = 0;
    
    CustomStack(int x) {
        st = stack<int>();
        maxSize = x;
    }
    
    void push(int x) {
        if (st.size() == maxSize)
            return;
        st.push(x);
    }
    
    int pop() {
        if (st.empty())
            return -1;
        int element = st.top();
        st.pop();
        return element;
    }
    
    void increment(int k, int val) {
        stack<int> aux;
        while (!st.empty()) {
            aux.push(st.top());
            st.pop();
        }
        
        int i = 0;
        while (i < k && !aux.empty()) {
            int curr = aux.top() + val;
            st.push(curr);
            aux.pop();
            i++;
        }
        
        while (!aux.empty()) {
            st.push(aux.top());
            aux.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */