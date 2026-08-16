class AllOne {
    struct BucketNode {
        int count;
        unordered_set<string> keys;
        BucketNode(int c) : count(c) {}
    };

    list<BucketNode> bucketList;
    unordered_map<string, list<BucketNode>::iterator> keyToBucketMap;

public:
    AllOne() {}

    void inc(string key) {
        if (!keyToBucketMap.count(key)) {
            if (bucketList.empty() || bucketList.front().count != 1) {
                bucketList.emplace_front(1);
            }
            bucketList.front().keys.insert(key);
            keyToBucketMap[key] = bucketList.begin();
        } else {
            auto currentBucket = keyToBucketMap[key];
            auto nextBucket = next(currentBucket);
            int nextCount = currentBucket->count + 1;

            if (nextBucket == bucketList.end() || nextBucket->count != nextCount) {
                nextBucket = bucketList.insert(nextBucket, BucketNode(nextCount));
            }

            nextBucket->keys.insert(key);
            keyToBucketMap[key] = nextBucket;

            currentBucket->keys.erase(key);
            if (currentBucket->keys.empty()) {
                bucketList.erase(currentBucket);
            }
        }
    }

    void dec(string key) {
        auto currentBucket = keyToBucketMap[key];
        if (currentBucket->count == 1) {
            keyToBucketMap.erase(key);
        } else {
            auto prevBucket = prev(currentBucket);
            int prevCount = currentBucket->count - 1;

            if (currentBucket == bucketList.begin() || prevBucket->count != prevCount) {
                prevBucket = bucketList.insert(currentBucket, BucketNode(prevCount));
            }

            prevBucket->keys.insert(key);
            keyToBucketMap[key] = prevBucket;
        }

        currentBucket->keys.erase(key);
        if (currentBucket->keys.empty()) {
            bucketList.erase(currentBucket);
        }
    }

    string getMaxKey() {
        return bucketList.empty() ? "" : *bucketList.back().keys.begin();
    }

    string getMinKey() {
        return bucketList.empty() ? "" : *bucketList.front().keys.begin();
    }
};
