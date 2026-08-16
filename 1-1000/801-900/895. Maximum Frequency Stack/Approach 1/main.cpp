class FreqStack {
    unordered_map<int, int> elementFrequency;
    unordered_map<int, stack<int>> frequencyGroupStacks;
    int maxFrequency;

public:
    FreqStack() : maxFrequency(0) {}

    void push(int val) {
        int freq = ++elementFrequency[val];
        maxFrequency = max(maxFrequency, freq);
        frequencyGroupStacks[freq].push(val);
    }

    int pop() {
        int topVal = frequencyGroupStacks[maxFrequency].top();
        frequencyGroupStacks[maxFrequency].pop();
        elementFrequency[topVal]--;
        if (frequencyGroupStacks[maxFrequency].empty()) {
            maxFrequency--;
        }
        return topVal;
    }
};
