class MaxStack {
    list<int> elementList;
    map<int, vector<list<int>::iterator>> valueToNodeIterators;

public:
    MaxStack() {}

    void push(int x) {
        elementList.push_front(x);
        valueToNodeIterators[x].push_back(elementList.begin());
    }

    int pop() {
        int val = elementList.front();
        elementList.pop_front();
        valueToNodeIterators[val].pop_back();
        if (valueToNodeIterators[val].empty()) {
            valueToNodeIterators.erase(val);
        }
        return val;
    }

    int top() {
        return elementList.front();
    }

    int peekMax() {
        return valueToNodeIterators.rbegin()->first;
    }

    int popMax() {
        int maxVal = valueToNodeIterators.rbegin()->first;
        auto nodeIter = valueToNodeIterators[maxVal].back();
        valueToNodeIterators[maxVal].pop_back();
        if (valueToNodeIterators[maxVal].empty()) {
            valueToNodeIterators.erase(maxVal);
        }
        elementList.erase(nodeIter);
        return maxVal;
    }
};
