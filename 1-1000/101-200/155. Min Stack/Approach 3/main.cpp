class MinStack {
    stack<pair<int, int>> elementStack; // pair of (val, current_min)

public:
    MinStack() {}

    void push(int val) {
        int currentMin = elementStack.empty() ? val : min(val, elementStack.top().second);
        elementStack.emplace(val, currentMin);
    }

    void pop() {
        elementStack.pop();
    }

    int top() {
        return elementStack.top().first;
    }

    int getMin() {
        return elementStack.top().second;
    }
};
