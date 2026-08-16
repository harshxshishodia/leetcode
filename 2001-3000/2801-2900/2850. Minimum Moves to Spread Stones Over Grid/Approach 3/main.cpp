class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> extra;
        vector<pair<int, int>> empty;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (grid[row][col] == 0) {
                    empty.push_back({
                        row,
                        col
                    });
                }

                for (int count = 1;
                     count < grid[row][col];
                     count++) {
                    extra.push_back({
                        row,
                        col
                    });
                }
            }
        }

        int count =
            static_cast<int>(extra.size());

        if (count == 0) {
            return 0;
        }

        int states =
            1 << count;

        const int INF =
            1000000000;

        vector<int> dp(
            states,
            INF
        );

        dp[0] = 0;

        for (int mask = 0; mask < states; mask++) {
            int index =
                __builtin_popcount(
                    static_cast<unsigned int>(mask)
                );

            if (index >= count ||
                dp[mask] == INF) {
                continue;
            }

            for (int target = 0;
                 target < count;
                 target++) {
                if ((mask & (1 << target)) != 0) {
                    continue;
                }

                int distance =
                    abs(
                        extra[index].first -
                        empty[target].first
                    ) +
                    abs(
                        extra[index].second -
                        empty[target].second
                    );

                dp[
                    mask |
                    (1 << target)
                ] = min(
                    dp[
                        mask |
                        (1 << target)
                    ],
                    dp[mask] +
                    distance
                );
            }
        }

        return dp[states - 1];
    }
};
