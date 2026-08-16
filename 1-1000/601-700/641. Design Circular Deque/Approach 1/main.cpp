class MyCircularDeque {
    vector<int> buffer;
    int headIndex;
    int tailIndex;
    int elementCount;
    int maxCapacity;

public:
    MyCircularDeque(int k)
        : buffer(k), headIndex(0), tailIndex(0), elementCount(0), maxCapacity(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        headIndex = (headIndex - 1 + maxCapacity) % maxCapacity;
        buffer[headIndex] = value;
        elementCount++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        buffer[tailIndex] = value;
        tailIndex = (tailIndex + 1) % maxCapacity;
        elementCount++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        headIndex = (headIndex + 1) % maxCapacity;
        elementCount--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        tailIndex = (tailIndex - 1 + maxCapacity) % maxCapacity;
        elementCount--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : buffer[headIndex];
    }

    int getRear() {
        return isEmpty() ? -1 : buffer[(tailIndex - 1 + maxCapacity) % maxCapacity];
    }

    bool isEmpty() {
        return elementCount == 0;
    }

    bool isFull() {
        return elementCount == maxCapacity;
    }
};
