class Bitset {
    string bitString;
    string invertedBitString;
    int onesTotalCount;
    int bitsetSize;
    bool isFlipped;

public:
    Bitset(int size)
        : bitString(size, '0'), invertedBitString(size, '1'), onesTotalCount(0), bitsetSize(size), isFlipped(false) {}

    void fix(int idx) {
        if (!isFlipped) {
            if (bitString[idx] == '0') {
                bitString[idx] = '1';
                invertedBitString[idx] = '0';
                onesTotalCount++;
            }
        } else {
            if (invertedBitString[idx] == '0') {
                invertedBitString[idx] = '1';
                bitString[idx] = '0';
                onesTotalCount++;
            }
        }
    }

    void unfix(int idx) {
        if (!isFlipped) {
            if (bitString[idx] == '1') {
                bitString[idx] = '0';
                invertedBitString[idx] = '1';
                onesTotalCount--;
            }
        } else {
            if (invertedBitString[idx] == '1') {
                invertedBitString[idx] = '0';
                bitString[idx] = '1';
                onesTotalCount--;
            }
        }
    }

    void flip() {
        isFlipped = !isFlipped;
        onesTotalCount = bitsetSize - onesTotalCount;
    }

    bool all() {
        return onesTotalCount == bitsetSize;
    }

    bool one() {
        return onesTotalCount > 0;
    }

    int count() {
        return onesTotalCount;
    }

    string toString() {
        return isFlipped ? invertedBitString : bitString;
    }
};
