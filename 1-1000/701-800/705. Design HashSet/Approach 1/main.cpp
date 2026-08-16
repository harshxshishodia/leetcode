class MyHashSet {
    vector<bool> lookupTable;

public:
    MyHashSet() : lookupTable(1000001, false) {}

    void add(int key) {
        lookupTable[key] = true;
    }

    void remove(int key) {
        lookupTable[key] = false;
    }

    bool contains(int key) {
        return lookupTable[key];
    }
};
