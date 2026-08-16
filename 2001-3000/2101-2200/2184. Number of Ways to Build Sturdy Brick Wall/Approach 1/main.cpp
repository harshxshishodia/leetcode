class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> rows;
    vector<vector<int>> compatible;

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
        int height,
        int level,
        int previous
    ) {
        if (level == height) {
            return 1;
        }

        long long answer = 0;

        if (previous == -1) {
            for (int row = 0;
                 row < static_cast<int>(rows.size());
                 row++) {
                answer +=
                    solve(
                        height,
                        level + 1,
                        row
                    );

                answer %= MOD;
            }
        } else {
            for (int row :
                 compatible[previous]) {
                answer +=
                    solve(
                        height,
                        level + 1,
                        row
                    );

                answer %= MOD;
            }
        }

        return static_cast<int>(answer);
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

        return solve(
            height,
            0,
            -1
        );
    }
};
