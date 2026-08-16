class NumberContainers {
    unordered_map<int, int> indexToNumberMap;
    unordered_map<int, set<int>> numberToIndicesMap;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumberMap.count(index)) {
            int oldNum = indexToNumberMap[index];
            numberToIndicesMap[oldNum].erase(index);
            if (numberToIndicesMap[oldNum].empty()) {
                numberToIndicesMap.erase(oldNum);
            }
        }
        indexToNumberMap[index] = number;
        numberToIndicesMap[number].insert(index);
    }

    int find(int number) {
        auto it = numberToIndicesMap.find(number);
        if (it == numberToIndicesMap.end() || it->second.empty()) {
            return -1;
        }
        return *it->second.begin();
    }
};
