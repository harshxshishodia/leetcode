class MyQueue {
    stack<int> primaryStack;
    stack<int> helperStack;

public:
    MyQueue() {}

    void push(int x) {
        while (!primaryStack.empty()) {
            helperStack.push(primaryStack.top());
            primaryStack.pop();
        }
        primaryStack.push(x);
        while (!helperStack.empty()) {
            primaryStack.push(helperStack.top());
            helperStack.pop();
        }
    }

    int pop() {
        int frontElement = primaryStack.top();
        primaryStack.pop();
        return frontElement;
    }

    int peek() {
        return primaryStack.top();
    }

    bool empty() {
        return primaryStack.empty();
    }
};
