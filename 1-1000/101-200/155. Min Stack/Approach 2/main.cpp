class MinStack {
    stack<int> primaryStack;
    stack<int> minTrackingStack;

public:
    MinStack() {}

    void push(int val) {
        primaryStack.push(val);
        if (minTrackingStack.empty() || val <= minTrackingStack.top()) {
            minTrackingStack.push(val);
        }
    }

    void pop() {
        if (primaryStack.top() == minTrackingStack.top()) {
            minTrackingStack.pop();
        }
        primaryStack.pop();
    }

    int top() {
        return primaryStack.top();
    }

    int getMin() {
        return minTrackingStack.top();
    }
};
