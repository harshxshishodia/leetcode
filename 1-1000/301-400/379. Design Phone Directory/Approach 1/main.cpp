class PhoneDirectory {
    unordered_set<int> availableNumbers;

public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) {
            availableNumbers.insert(i);
        }
    }

    int get() {
        if (availableNumbers.empty()) return -1;
        int num = *availableNumbers.begin();
        availableNumbers.erase(availableNumbers.begin());
        return num;
    }

    bool check(int number) {
        return availableNumbers.count(number);
    }

    void release(int number) {
        availableNumbers.insert(number);
    }
};
