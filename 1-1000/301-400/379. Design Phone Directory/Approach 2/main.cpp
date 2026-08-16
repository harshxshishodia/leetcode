class PhoneDirectory {
    vector<bool> isAssigned;
    queue<int> availablePool;

public:
    PhoneDirectory(int maxNumbers) : isAssigned(maxNumbers, false) {
        for (int i = 0; i < maxNumbers; i++) {
            availablePool.push(i);
        }
    }

    int get() {
        if (availablePool.empty()) return -1;
        int assignedNumber = availablePool.front();
        availablePool.pop();
        isAssigned[assignedNumber] = true;
        return assignedNumber;
    }

    bool check(int number) {
        if (number < 0 || number >= static_cast<int>(isAssigned.size())) return false;
        return !isAssigned[number];
    }

    void release(int number) {
        if (number >= 0 && number < static_cast<int>(isAssigned.size()) && isAssigned[number]) {
            isAssigned[number] = false;
            availablePool.push(number);
        }
    }
};
