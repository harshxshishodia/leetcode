class TextEditor {
    string leftSideText;
    string rightSideText;

public:
    TextEditor() {}

    void addText(string text) {
        leftSideText += text;
    }

    int deleteText(int k) {
        int deleteCount = min(k, static_cast<int>(leftSideText.size()));
        leftSideText.erase(leftSideText.size() - deleteCount);
        return deleteCount;
    }

    string cursorLeft(int k) {
        int moveCount = min(k, static_cast<int>(leftSideText.size()));
        while (moveCount--) {
            rightSideText.push_back(leftSideText.back());
            leftSideText.pop_back();
        }
        int resultLen = min(10, static_cast<int>(leftSideText.size()));
        return leftSideText.substr(leftSideText.size() - resultLen);
    }

    string cursorRight(int k) {
        int moveCount = min(k, static_cast<int>(rightSideText.size()));
        while (moveCount--) {
            leftSideText.push_back(rightSideText.back());
            rightSideText.pop_back();
        }
        int resultLen = min(10, static_cast<int>(leftSideText.size()));
        return leftSideText.substr(leftSideText.size() - resultLen);
    }
};
