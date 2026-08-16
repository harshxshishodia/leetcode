class Solution {
public:
    int minimumLines(vector<vector<int>>& points) {
        int n =
            static_cast<int>(points.size());

        if (n <= 2) {
            return 1;
        }

        vector<int> lines;

        for (int first = 0; first < n; first++) {
            for (int second = first + 1;
                 second < n;
                 second++) {
                int mask = 0;

                for (int third = 0; third < n; third++) {
                    long long cross =
                        1LL *
                        (points[second][0] - points[first][0]) *
                        (points[third][1] - points[first][1]) -
                        1LL *
                        (points[second][1] - points[first][1]) *
                        (points[third][0] - points[first][0]);

                    if (cross == 0) {
                        mask |=
                            1 << third;
                    }
                }

                lines.push_back(mask);
            }
        }

        int states =
            1 << n;

        vector<int> dp(
            states,
            n
        );

        dp[0] = 0;

        for (int mask = 0; mask < states; mask++) {
            if (dp[mask] == n) {
                continue;
            }

            for (int line : lines) {
                dp[mask | line] = min(
                    dp[mask | line],
                    dp[mask] + 1
                );
            }
        }

        return dp[states - 1];
    }
};
