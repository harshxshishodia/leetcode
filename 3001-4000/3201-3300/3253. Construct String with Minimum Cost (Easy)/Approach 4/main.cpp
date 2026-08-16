class Solution {
    struct Node {
        array<int, 26> next;
        int cost;

        Node() : cost(1000000000) {
            next.fill(-1);
        }
    };

public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        const int INF = 1000000000;
        vector<Node> trie(1);

        for (int i = 0; i < static_cast<int>(words.size()); i++) {
            int node = 0;

            for (char character : words[i]) {
                int index = character - 'a';

                if (trie[node].next[index] == -1) {
                    trie[node].next[index] = static_cast<int>(trie.size());
                    trie.push_back(Node());
                }

                node = trie[node].next[index];
            }

            trie[node].cost = min(trie[node].cost, costs[i]);
        }

        int n = static_cast<int>(target.size());
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int start = 0; start < n; start++) {
            if (dp[start] == INF) {
                continue;
            }

            int node = 0;

            for (int end = start; end < n; end++) {
                int index = target[end] - 'a';

                if (trie[node].next[index] == -1) {
                    break;
                }

                node = trie[node].next[index];

                if (trie[node].cost != INF) {
                    dp[end + 1] = min(
                        dp[end + 1],
                        dp[start] + trie[node].cost
                    );
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
