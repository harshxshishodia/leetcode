class RandomizedSet {
    vector<int> valueList;
    unordered_map<int, int> valueToIndex;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valueToIndex.find(val) != valueToIndex.end()) {
            return false;
        }
        valueToIndex[val] = static_cast<int>(valueList.size());
        valueList.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = valueToIndex.find(val);
        if (it == valueToIndex.end()) {
            return false;
        }
        int indexToRemove = it->second;
        int lastValue = valueList.back();

        valueList[indexToRemove] = lastValue;
        valueToIndex[lastValue] = indexToRemove;

        valueList.pop_back();
        valueToIndex.erase(val);
        return true;
    }

    int getRandom() {
        return valueList[rand() % valueList.size()];
    }
};
