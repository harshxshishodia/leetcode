class MyHashSet {
    static const int BUCKET_COUNT = 10007;
    vector<list<int>> bucketArray;

    int hashKey(int key) {
        return key % BUCKET_COUNT;
    }

public:
    MyHashSet() : bucketArray(BUCKET_COUNT) {}

    void add(int key) {
        int index = hashKey(key);
        auto& bucket = bucketArray[index];
        if (find(bucket.begin(), bucket.end(), key) == bucket.end()) {
            bucket.push_back(key);
        }
    }

    void remove(int key) {
        int index = hashKey(key);
        auto& bucket = bucketArray[index];
        auto it = find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it);
        }
    }

    bool contains(int key) {
        int index = hashKey(key);
        const auto& bucket = bucketArray[index];
        return find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};
