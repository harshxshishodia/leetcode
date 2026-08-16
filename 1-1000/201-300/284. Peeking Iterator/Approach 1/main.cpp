class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    int next();
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
    int cachedNextValue;
    bool hasNextFlag;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasNextFlag = Iterator::hasNext();
        if (hasNextFlag) {
            cachedNextValue = Iterator::next();
        }
    }

    int peek() {
        return cachedNextValue;
    }

    int next() {
        int result = cachedNextValue;
        hasNextFlag = Iterator::hasNext();
        if (hasNextFlag) {
            cachedNextValue = Iterator::next();
        }
        return result;
    }

    bool hasNext() const {
        return hasNextFlag;
    }
};
