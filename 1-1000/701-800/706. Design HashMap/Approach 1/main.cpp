class MyHashMap {
    vector<int> directTable;

public:
    MyHashMap() : directTable(1000001, -1) {}

    void put(int key, int value) {
        directTable[key] = value;
    }

    int get(int key) {
        return directTable[key];
    }

    void remove(int key) {
        directTable[key] = -1;
    }
};
