class LUPrefix {
    vector<bool> isUploaded;
    int longestPrefixPointer;

public:
    LUPrefix(int n) : isUploaded(n + 2, false), longestPrefixPointer(1) {}

    void upload(int video) {
        isUploaded[video] = true;
        while (isUploaded[longestPrefixPointer]) {
            longestPrefixPointer++;
        }
    }

    int longest() {
        return longestPrefixPointer - 1;
    }
};
