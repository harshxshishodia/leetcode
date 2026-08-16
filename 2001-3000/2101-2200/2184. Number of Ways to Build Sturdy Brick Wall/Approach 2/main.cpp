class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> rows;
    vector<vector<int>> compatible;
    vector<vector<int>> memo;

    void buildRows(
        int width,
        const vector<int>& bricks,
        int used,
        int mask
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
                nextMask
            );
        }
    }

    int solve(
        int remaining,
        int previous
    ) {
        if (remaining == 0) {
            return 1;
        }

        if (memo[remaining][previous] != -1) {
            return memo[remaining][previous];
        }

        long long answer = 0;

        for (int row :
             compatible[previous]) {
            answer +=
                solve(
                    remaining - 1,
                    row
                );

            answer %= MOD;
        }

        memo[remaining][previous] =
            static_cast<int>(answer);

        return memo[remaining][previous];
    }

public:
    int buildWall(
        int height,
        int width,
        vector<int>& bricks
    ) {
        rows.clear();

        buildRows(
            width,
            bricks,
            0,
            0
        );

        int count =
            static_cast<int>(rows.size());

        if (height == 1) {
            return count;
        }

        compatible.assign(
            count,
            {}
        );

        for (int first = 0; first < count; first++) {
            for (int second = 0; second < count; second++) {
                if ((rows[first] &
                     rows[second]) == 0) {
                    compatible[first].push_back(
                        second
                    );
                }
            }
        }

        memo.assign(
            height,
            vector<int>(
                count,
                -1
            )
        );

        long long answer = 0;

        for (int first = 0; first < count; first++) {
            answer +=
                solve(
                    height - 1,
                    first
                );

            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
