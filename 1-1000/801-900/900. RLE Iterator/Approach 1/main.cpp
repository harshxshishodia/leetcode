class RLEIterator {
    vector<int> encodedData;
    int currentIndex;

public:
    RLEIterator(vector<int>& encoding) : encodedData(encoding), currentIndex(0) {}

    int next(int n) {
        while (currentIndex < static_cast<int>(encodedData.size())) {
            if (encodedData[currentIndex] >= n) {
                encodedData[currentIndex] -= n;
                return encodedData[currentIndex + 1];
            } else {
                n -= encodedData[currentIndex];
                currentIndex += 2;
            }
        }
        return -1;
    }
};
