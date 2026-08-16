class Allocator {
    vector<int> memoryBlocks;
    int totalSize;

public:
    Allocator(int n) : memoryBlocks(n, 0), totalSize(n) {}

    int allocate(int size, int mID) {
        int consecutiveFree = 0;
        for (int i = 0; i < totalSize; i++) {
            if (memoryBlocks[i] == 0) {
                consecutiveFree++;
                if (consecutiveFree == size) {
                    int startIndex = i - size + 1;
                    for (int j = startIndex; j <= i; j++) {
                        memoryBlocks[j] = mID;
                    }
                    return startIndex;
                }
            } else {
                consecutiveFree = 0;
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        int freedCount = 0;
        for (int i = 0; i < totalSize; i++) {
            if (memoryBlocks[i] == mID) {
                memoryBlocks[i] = 0;
                freedCount++;
            }
        }
        return freedCount;
    }
};
