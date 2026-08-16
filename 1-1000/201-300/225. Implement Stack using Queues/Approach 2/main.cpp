class MyStack {
    queue<int> mainQueue;

public:
    MyStack() {}

    void push(int x) {
        mainQueue.push(x);
        int currentSize = static_cast<int>(mainQueue.size());
        for (int i = 0; i < currentSize - 1; i++) {
            mainQueue.push(mainQueue.front());
            mainQueue.pop();
        }
    }

    int pop() {
        int topValue = mainQueue.front();
        mainQueue.pop();
        return topValue;
    }

    int top() {
        return mainQueue.front();
    }

    bool empty() {
        return mainQueue.empty();
    }
};
