class StringIterator {
    string uncompressed;
    int currentIndex;

public:
    StringIterator(string compressedString) : currentIndex(0) {
        int i = 0;
        int n = static_cast<int>(compressedString.size());
        while (i < n) {
            char ch = compressedString[i++];
            long long count = 0;
            while (i < n && isdigit(compressedString[i])) {
                count = count * 10 + (compressedString[i++] - '0');
            }
            uncompressed.append(count, ch);
        }
    }

    char next() {
        if (!hasNext()) {
            return ' ';
        }
        return uncompressed[currentIndex++];
    }

    bool hasNext() {
        return currentIndex < static_cast<int>(uncompressed.size());
    }
};
