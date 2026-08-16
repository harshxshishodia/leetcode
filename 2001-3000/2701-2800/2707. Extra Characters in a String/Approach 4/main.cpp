class Solution {
    struct Node {
        array<int, 26> next;
        bool terminal;

        Node() :
            terminal(false) {
            next.fill(-1);
        }
    };

public:
    int minExtraChar(
        string s,
        vector<string>& dictionary
    ) {
        vector<Node> trie(1);

        for (const string& word :
             dictionary) {
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

            trie[node].terminal =
                true;
        }

        int n =
            static_cast<int>(s.size());

        vector<int> dp(
            n + 1
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            dp[index] =
                1 +
                dp[index + 1];

            int node = 0;

            for (int end = index;
                 end < n;
                 end++) {
                int edge =
                    s[end] -
                    'a';

                if (trie[node].next[edge] == -1) {
                    break;
                }

                node =
                    trie[node].next[edge];

                if (trie[node].terminal) {
                    dp[index] = min(
                        dp[index],
                        dp[end + 1]
                    );
                }
            }
        }

        return dp[0];
    }
};
