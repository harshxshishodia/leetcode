class SmallestInfiniteSet {
    int currentSmallest;
    set<int> addedBackNumbers;

public:
    SmallestInfiniteSet() : currentSmallest(1) {}

    int popSmallest() {
        if (!addedBackNumbers.empty()) {
            int smallest = *addedBackNumbers.begin();
            addedBackNumbers.erase(addedBackNumbers.begin());
            return smallest;
        }
        return currentSmallest++;
    }

    void addBack(int num) {
        if (num < currentSmallest) {
            addedBackNumbers.insert(num);
        }
    }
};
