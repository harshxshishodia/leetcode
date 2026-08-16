class MyHashMap {
    static const int BUCKET_COUNT = 10007;
    vector<list<pair<int, int>>> bucketTable;

    int hashKey(int key) {
        return key % BUCKET_COUNT;
    }

public:
    MyHashMap() : bucketTable(BUCKET_COUNT) {}

    void put(int key, int value) {
        int index = hashKey(key);
        auto& bucket = bucketTable[index];
        for (auto& [existingKey, existingValue] : bucket) {
            if (existingKey == key) {
                existingValue = value;
                return;
            }
        }
        bucket.emplace_back(key, value);
    }

    int get(int key) {
        int index = hashKey(key);
        const auto& bucket = bucketTable[index];
        for (const auto& [existingKey, existingValue] : bucket) {
            if (existingKey == key) {
                return existingValue;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = hashKey(key);
        auto& bucket = bucketTable[index];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};
