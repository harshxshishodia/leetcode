class DinnerPlates {
    int stackCapacity;
    vector<vector<int>> plateStacks;
    set<int> availableStackIndices;

public:
    DinnerPlates(int capacity) : stackCapacity(capacity) {}

    void push(int val) {
        if (availableStackIndices.empty()) {
            plateStacks.emplace_back();
            availableStackIndices.insert(plateStacks.size() - 1);
        }
        int targetStackIdx = *availableStackIndices.begin();
        plateStacks[targetStackIdx].push_back(val);
        if (static_cast<int>(plateStacks[targetStackIdx].size()) == stackCapacity) {
            availableStackIndices.erase(targetStackIdx);
        }
    }

    int pop() {
        while (!plateStacks.empty() && plateStacks.back().empty()) {
            availableStackIndices.erase(plateStacks.size() - 1);
            plateStacks.pop_back();
        }
        if (plateStacks.empty()) return -1;
        return popAtStack(plateStacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index < 0 || index >= static_cast<int>(plateStacks.size()) || plateStacks[index].empty()) {
            return -1;
        }
        int val = plateStacks[index].back();
        plateStacks[index].pop_back();
        availableStackIndices.insert(index);
        return val;
    }
};
