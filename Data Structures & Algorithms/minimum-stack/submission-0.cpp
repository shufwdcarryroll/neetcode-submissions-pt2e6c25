#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;       // Main stack
    stack<int> minSt;    // Stack to track minimums

public:
    MinStack() {
        // Nothing to initialize explicitly
    }
    
    void push(int val) {
        st.push(val);
        // Push onto minSt if it's empty or val <= current min
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
