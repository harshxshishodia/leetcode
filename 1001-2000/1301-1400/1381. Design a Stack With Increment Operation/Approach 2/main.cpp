class CustomStack {
    vector<int> stackElements;
    vector<int> lazyIncrements;
    int maxCapacity;

public:
    CustomStack(int maxSize) : maxCapacity(maxSize) {}

    void push(int x) {
        if (static_cast<int>(stackElements.size()) < maxCapacity) {
            stackElements.push_back(x);
            lazyIncrements.push_back(0);
        }
    }

    int pop() {
        if (stackElements.empty()) return -1;
        int index = static_cast<int>(stackElements.size()) - 1;
        int value = stackElements.back() + lazyIncrements[index];
        if (index > 0) {
            lazyIncrements[index - 1] += lazyIncrements[index];
        }
        stackElements.pop_back();
        lazyIncrements.pop_back();
        return value;
    }

    void increment(int k, int val) {
        int index = min(static_cast<int>(stackElements.size()), k) - 1;
        if (index >= 0) {
            lazyIncrements[index] += val;
        }
    }
};
