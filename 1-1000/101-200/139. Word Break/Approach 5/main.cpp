class Solution {
    struct Node {
        array<int, 26> next;
        bool terminal;

        Node() : terminal(false) {
            next.fill(-1);
        }
    };

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<Node> trie(1);

        for (const string& word : wordDict) {
            int node = 0;

            for (char character : word) {
                int index = character - 'a';

                if (trie[node].next[index] == -1) {
                    trie[node].next[index] = static_cast<int>(trie.size());
                    trie.push_back(Node());
                }

                node = trie[node].next[index];
            }

            trie[node].terminal = true;
        }

        int n = static_cast<int>(s.size());
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int start = 0; start < n; start++) {
            if (!dp[start]) {
                continue;
            }

            int node = 0;

            for (int end = start; end < n; end++) {
                int index = s[end] - 'a';

                if (trie[node].next[index] == -1) {
                    break;
                }

                node = trie[node].next[index];

                if (trie[node].terminal) {
                    dp[end + 1] = true;
                }
            }
        }

        return dp[n];
    }
};
