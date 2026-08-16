class BrowserHistory {
    stack<string> backHistoryStack;
    stack<string> forwardHistoryStack;
    string currentUrl;

public:
    BrowserHistory(string homepage) : currentUrl(homepage) {}

    void visit(string url) {
        backHistoryStack.push(currentUrl);
        currentUrl = url;
        while (!forwardHistoryStack.empty()) {
            forwardHistoryStack.pop();
        }
    }

    string back(int steps) {
        while (steps > 0 && !backHistoryStack.empty()) {
            forwardHistoryStack.push(currentUrl);
            currentUrl = backHistoryStack.top();
            backHistoryStack.pop();
            steps--;
        }
        return currentUrl;
    }

    string forward(int steps) {
        while (steps > 0 && !forwardHistoryStack.empty()) {
            backHistoryStack.push(currentUrl);
            currentUrl = forwardHistoryStack.top();
            forwardHistoryStack.pop();
            steps--;
        }
        return currentUrl;
    }
};
