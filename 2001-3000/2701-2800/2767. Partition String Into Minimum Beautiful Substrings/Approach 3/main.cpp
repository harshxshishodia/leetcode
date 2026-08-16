class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n =
            static_cast<int>(s.size());

        unordered_set<string> beautiful;

        long long value = 1;

        while (true) {
            string binary;

            long long current =
                value;

            while (current > 0) {
                binary.push_back(
                    static_cast<char>(
                        '0' +
                        current % 2
                    )
                );

                current /=
                    2;
            }

            reverse(
                binary.begin(),
                binary.end()
            );

            if (static_cast<int>(binary.size()) > n) {
                break;
            }

            beautiful.insert(
                binary
            );

            value *=
                5;
        }

        const int INF =
            1000000000;

        vector<int> dp(
            n + 1,
            INF
        );

        dp[0] = 0;

        for (int end = 1;
             end <= n;
             end++) {
            for (int start = 0;
                 start < end;
                 start++) {
                if (dp[start] == INF) {
                    continue;
                }

                if (beautiful.count(
                        s.substr(
                            start,
                            end - start
                        ))) {
                    dp[end] = min(
                        dp[end],
                        dp[start] + 1
                    );
                }
            }
        }

        return dp[n] == INF
            ? -1
            : dp[n];
    }
};
