class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = static_cast<int>(s.size());
        vector<bool> visited(n + 1);
        queue<int> pending;
        pending.push(0);

        while (!pending.empty()) {
            int start = pending.front();
            pending.pop();

            if (visited[start]) {
                continue;
            }

            visited[start] = true;

            for (int end = start + 1; end <= n; end++) {
                if (!words.count(s.substr(start, end - start))) {
                    continue;
                }

                if (end == n) {
                    return true;
                }

                if (!visited[end]) {
                    pending.push(end);
                }
            }
        }

        return false;
    }
};
