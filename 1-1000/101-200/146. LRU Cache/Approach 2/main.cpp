class LRUCache {
    int capacity;
    list<pair<int, int>> cacheList; // pair of (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> keyToIterator;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = keyToIterator.find(key);
        if (it == keyToIterator.end()) {
            return -1;
        }
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = keyToIterator.find(key);
        if (it != keyToIterator.end()) {
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            it->second->second = value;
            return;
        }

        if (static_cast<int>(keyToIterator.size()) == capacity) {
            int lruKey = cacheList.back().first;
            cacheList.pop_back();
            keyToIterator.erase(lruKey);
        }

        cacheList.emplace_front(key, value);
        keyToIterator[key] = cacheList.begin();
    }
};
