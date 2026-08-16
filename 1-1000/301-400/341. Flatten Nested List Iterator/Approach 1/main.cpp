class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    vector<int> flattenedList;
    int currentIndex;

    void flatten(const vector<NestedInteger>& nestedList) {
        for (const auto& item : nestedList) {
            if (item.isInteger()) {
                flattenedList.push_back(item.getInteger());
            } else {
                flatten(item.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) : currentIndex(0) {
        flatten(nestedList);
    }

    int next() {
        return flattenedList[currentIndex++];
    }

    bool hasNext() {
        return currentIndex < static_cast<int>(flattenedList.size());
    }
};
