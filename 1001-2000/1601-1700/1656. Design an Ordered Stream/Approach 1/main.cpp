class OrderedStream {
    unordered_map<int, string> streamStorage;
    int currentPointer;

public:
    OrderedStream(int n) : currentPointer(1) {}

    vector<string> insert(int idKey, string value) {
        streamStorage[idKey] = value;
        vector<string> chunk;
        while (streamStorage.find(currentPointer) != streamStorage.end()) {
            chunk.push_back(streamStorage[currentPointer++]);
        }
        return chunk;
    }
};
