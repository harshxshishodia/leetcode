class Solution {
    static constexpr int MOD =
        1000000007;

    void buildRows(
        int width,
        const vector<int>& bricks,
        int used,
        int mask,
        vector<int>& rows
    ) {
        if (used == width) {
            rows.push_back(mask);
            return;
        }

        for (int brick : bricks) {
            int next =
                used + brick;

            if (next > width) {
                continue;
            }

            int nextMask =
                mask;

            if (next < width) {
                nextMask |=
                    1 << next;
            }

            buildRows(
                width,
                bricks,
                next,
                nextMask,
                rows
            );
        }
    }

public:
    int buildWall(
        int height,
        int width,
        vector<int>& bricks
    ) {
        vector<int> rows;

        buildRows(
            width,
            bricks,
            0,
            0,
            rows
        );

        int count =
            static_cast<int>(rows.size());

        vector<vector<int>> graph(
            count
        );

        for (int first = 0; first < count; first++) {
            for (int second = 0; second < count; second++) {
                if ((rows[first] &
                     rows[second]) == 0) {
                    graph[first].push_back(
                        second
                    );
                }
            }
        }

        vector<long long> dp(
            count,
            1
        );

        for (int level = 1;
             level < height;
             level++) {
            vector<long long> next(
                count
            );

            for (int first = 0; first < count; first++) {
                for (int second :
                     graph[first]) {
                    next[second] +=
                        dp[first];

                    next[second] %=
                        MOD;
                }
            }

            dp = next;
        }

        long long answer = 0;

        for (long long ways : dp) {
            answer += ways;
            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
