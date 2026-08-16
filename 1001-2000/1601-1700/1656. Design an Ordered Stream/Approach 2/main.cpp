class OrderedStream {
    vector<string> streamBuffer;
    int currentPointer;

public:
    OrderedStream(int n) : streamBuffer(n + 2, ""), currentPointer(1) {}

    vector<string> insert(int idKey, string value) {
        streamBuffer[idKey] = value;
        vector<string> resultChunk;
        while (currentPointer < static_cast<int>(streamBuffer.size()) && !streamBuffer[currentPointer].empty()) {
            resultChunk.push_back(streamBuffer[currentPointer++]);
        }
        return resultChunk;
    }
};
