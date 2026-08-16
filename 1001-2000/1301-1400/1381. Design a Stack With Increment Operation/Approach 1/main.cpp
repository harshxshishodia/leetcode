class CustomStack {
    vector<int> stackElements;
    int maxCapacity;

public:
    CustomStack(int maxSize) : maxCapacity(maxSize) {}

    void push(int x) {
        if (static_cast<int>(stackElements.size()) < maxCapacity) {
            stackElements.push_back(x);
        }
    }

    int pop() {
        if (stackElements.empty()) return -1;
        int value = stackElements.back();
        stackElements.pop_back();
        return value;
    }

    void increment(int k, int val) {
        int limit = min(k, static_cast<int>(stackElements.size()));
        for (int i = 0; i < limit; i++) {
            stackElements[i] += val;
        }
    }
};
