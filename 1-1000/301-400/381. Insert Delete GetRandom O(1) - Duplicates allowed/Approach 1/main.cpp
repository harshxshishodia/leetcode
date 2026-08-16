class RandomizedCollection {
    vector<int> valueList;
    unordered_map<int, unordered_set<int>> valueIndicesMap;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool isFirstInstance = (valueIndicesMap[val].empty());
        valueIndicesMap[val].insert(valueList.size());
        valueList.push_back(val);
        return isFirstInstance;
    }

    bool remove(int val) {
        if (valueIndicesMap[val].empty()) {
            return false;
        }
        int indexToRemove = *valueIndicesMap[val].begin();
        valueIndicesMap[val].erase(indexToRemove);

        int lastIndex = static_cast<int>(valueList.size()) - 1;
        int lastValue = valueList[lastIndex];

        if (indexToRemove != lastIndex) {
            valueList[indexToRemove] = lastValue;
            valueIndicesMap[lastValue].erase(lastIndex);
            valueIndicesMap[lastValue].insert(indexToRemove);
        }

        valueList.pop_back();
        return true;
    }

    int getRandom() {
        return valueList[rand() % valueList.size()];
    }
};
