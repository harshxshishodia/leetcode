class MyStack {
    queue<int> primaryQueue;
    queue<int> helperQueue;

public:
    MyStack() {}

    void push(int x) {
        helperQueue.push(x);
        while (!primaryQueue.empty()) {
            helperQueue.push(primaryQueue.front());
            primaryQueue.pop();
        }
        swap(primaryQueue, helperQueue);
    }

    int pop() {
        int topElement = primaryQueue.front();
        primaryQueue.pop();
        return topElement;
    }

    int top() {
        return primaryQueue.front();
    }

    bool empty() {
        return primaryQueue.empty();
    }
};
