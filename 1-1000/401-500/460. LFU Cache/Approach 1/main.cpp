class LFUCache {
    struct CacheNode {
        int key;
        int value;
        int frequency;
    };

    int maxCapacity;
    int minFrequency;
    unordered_map<int, CacheNode> keyToNodeMap;
    unordered_map<int, list<int>> frequencyToKeysMap;
    unordered_map<int, list<int>::iterator> keyToListIteratorMap;

public:
    LFUCache(int capacity) : maxCapacity(capacity), minFrequency(0) {}

    int get(int key) {
        if (!keyToNodeMap.count(key)) return -1;

        int val = keyToNodeMap[key].value;
        int freq = keyToNodeMap[key].frequency;

        frequencyToKeysMap[freq].erase(keyToListIteratorMap[key]);
        if (frequencyToKeysMap[freq].empty()) {
            frequencyToKeysMap.erase(freq);
            if (minFrequency == freq) {
                minFrequency++;
            }
        }

        freq++;
        keyToNodeMap[key].frequency = freq;
        frequencyToKeysMap[freq].push_front(key);
        keyToListIteratorMap[key] = frequencyToKeysMap[freq].begin();

        return val;
    }

    void put(int key, int value) {
        if (maxCapacity <= 0) return;

        if (keyToNodeMap.count(key)) {
            keyToNodeMap[key].value = value;
            get(key);
            return;
        }

        if (static_cast<int>(keyToNodeMap.size()) == maxCapacity) {
            int evictKey = frequencyToKeysMap[minFrequency].back();
            frequencyToKeysMap[minFrequency].pop_back();
            if (frequencyToKeysMap[minFrequency].empty()) {
                frequencyToKeysMap.erase(minFrequency);
            }
            keyToNodeMap.erase(evictKey);
            keyToListIteratorMap.erase(evictKey);
        }

        minFrequency = 1;
        keyToNodeMap[key] = {key, value, 1};
        frequencyToKeysMap[1].push_front(key);
        keyToListIteratorMap[key] = frequencyToKeysMap[1].begin();
    }
};
