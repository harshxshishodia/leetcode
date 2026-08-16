class Solution {
    struct Node {
        array<int, 26> next;

        Node() {
            next.fill(-1);
        }
    };

public:
    int minValidStrings(
        vector<string>& words,
        string target
    ) {
        vector<Node> trie(1);

        for (const string& word :
             words) {
            int node = 0;

            for (char character :
                 word) {
                int edge =
                    character -
                    'a';

                if (trie[node].next[edge] == -1) {
                    trie[node].next[edge] =
                        static_cast<int>(
                            trie.size()
                        );

                    trie.push_back(
                        Node()
                    );
                }

                node =
                    trie[node].next[edge];
            }
        }

        int n =
            static_cast<int>(target.size());

        const int INF =
            1000000000;

        vector<int> dp(
            n + 1,
            INF
        );

        dp[n] =
            0;

        for (int index = n - 1;
             index >= 0;
             index--) {
            int node = 0;

            for (int end = index;
                 end < n;
                 end++) {
                int edge =
                    target[end] -
                    'a';

                if (trie[node].next[edge] == -1) {
                    break;
                }

                node =
                    trie[node].next[edge];

                if (dp[end + 1] != INF) {
                    dp[index] = min(
                        dp[index],
                        1 +
                        dp[end + 1]
                    );
                }
            }
        }

        return dp[0] == INF
            ? -1
            : dp[0];
    }
};
