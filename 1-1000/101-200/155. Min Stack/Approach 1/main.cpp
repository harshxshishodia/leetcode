class MinStack {
    vector<int> stackElements;

public:
    MinStack() {}

    void push(int val) {
        stackElements.push_back(val);
    }

    void pop() {
        stackElements.pop_back();
    }

    int top() {
        return stackElements.back();
    }

    int getMin() {
        int currentMin = stackElements[0];
        for (int x : stackElements) {
            currentMin = min(currentMin, x);
        }
        return currentMin;
    }
};
