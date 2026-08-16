class MyQueue {
    stack<int> inputStack;
    stack<int> outputStack;

    void shiftStacks() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        shiftStacks();
        int frontValue = outputStack.top();
        outputStack.pop();
        return frontValue;
    }

    int peek() {
        shiftStacks();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
