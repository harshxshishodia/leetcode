class ZigzagIterator {
    vector<int> interleaved;
    int currentIndex;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : currentIndex(0) {
        int i = 0, j = 0;
        int n1 = static_cast<int>(v1.size());
        int n2 = static_cast<int>(v2.size());
        while (i < n1 || j < n2) {
            if (i < n1) {
                interleaved.push_back(v1[i++]);
            }
            if (j < n2) {
                interleaved.push_back(v2[j++]);
            }
        }
    }

    int next() {
        return interleaved[currentIndex++];
    }

    bool hasNext() {
        return currentIndex < static_cast<int>(interleaved.size());
    }
};
