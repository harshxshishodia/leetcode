class MyCircularQueue {
    vector<int> buffer;
    int headIndex;
    int tailIndex;
    int elementCount;
    int maxCapacity;

public:
    MyCircularQueue(int k)
        : buffer(k), headIndex(0), tailIndex(0), elementCount(0), maxCapacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        buffer[tailIndex] = value;
        tailIndex = (tailIndex + 1) % maxCapacity;
        elementCount++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        headIndex = (headIndex + 1) % maxCapacity;
        elementCount--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : buffer[headIndex];
    }

    int Rear() {
        return isEmpty() ? -1 : buffer[(tailIndex - 1 + maxCapacity) % maxCapacity];
    }

    bool isEmpty() {
        return elementCount == 0;
    }

    bool isFull() {
        return elementCount == maxCapacity;
    }
};
