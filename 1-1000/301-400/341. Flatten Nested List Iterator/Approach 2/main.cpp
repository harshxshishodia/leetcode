class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    using IteratorType = vector<NestedInteger>::const_iterator;
    stack<pair<IteratorType, IteratorType>> iteratorStack;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        iteratorStack.push({nestedList.cbegin(), nestedList.cend()});
    }

    int next() {
        hasNext();
        return (iteratorStack.top().first++)->getInteger();
    }

    bool hasNext() {
        while (!iteratorStack.empty()) {
            if (iteratorStack.top().first == iteratorStack.top().second) {
                iteratorStack.pop();
            } else {
                auto it = iteratorStack.top().first;
                if (it->isInteger()) {
                    return true;
                }
                iteratorStack.top().first++;
                iteratorStack.push({it->getList().cbegin(), it->getList().cend()});
            }
        }
        return false;
    }
};
