class StringIterator {
    string compressed;
    int pointer;
    char currentChar;
    long long remainingCount;

public:
    StringIterator(string compressedString)
        : compressed(compressedString), pointer(0), currentChar(' '), remainingCount(0) {}

    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (remainingCount == 0) {
            currentChar = compressed[pointer++];
            remainingCount = 0;
            while (pointer < static_cast<int>(compressed.size()) && isdigit(compressed[pointer])) {
                remainingCount = remainingCount * 10 + (compressed[pointer++] - '0');
            }
        }
        remainingCount--;
        return currentChar;
    }

    bool hasNext() {
        return remainingCount > 0 || pointer < static_cast<int>(compressed.size());
    }
};
