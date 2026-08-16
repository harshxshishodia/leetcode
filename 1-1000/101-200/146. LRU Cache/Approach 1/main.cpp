class LRUCache {
    struct CacheNode {
        int key;
        int value;
        int accessTimestamp;
    };

    vector<CacheNode> cacheStorage;
    int cacheCapacity;
    int currentTimer;

public:
    LRUCache(int capacity) : cacheCapacity(capacity), currentTimer(0) {}

    int get(int key) {
        currentTimer++;
        for (auto& item : cacheStorage) {
            if (item.key == key) {
                item.accessTimestamp = currentTimer;
                return item.value;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        currentTimer++;
        for (auto& item : cacheStorage) {
            if (item.key == key) {
                item.value = value;
                item.accessTimestamp = currentTimer;
                return;
            }
        }

        if (static_cast<int>(cacheStorage.size()) == cacheCapacity) {
            int oldestIndex = 0;
            for (int i = 1; i < static_cast<int>(cacheStorage.size()); i++) {
                if (cacheStorage[i].accessTimestamp < cacheStorage[oldestIndex].accessTimestamp) {
                    oldestIndex = i;
                }
            }
            cacheStorage.erase(cacheStorage.begin() + oldestIndex);
        }

        cacheStorage.push_back({key, value, currentTimer});
    }
};
