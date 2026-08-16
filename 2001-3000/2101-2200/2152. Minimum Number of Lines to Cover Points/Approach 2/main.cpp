class Solution {
    vector<int> memo;
    vector<vector<int>> lineMask;
    int n;

    int solve(int covered) {
        int full =
            (1 << n) -
            1;

        if (covered == full) {
            return 0;
        }

        if (memo[covered] != -1) {
            return memo[covered];
        }

        int first = 0;

        while ((covered & (1 << first)) != 0) {
            first++;
        }

        int uncovered =
            n -
            __builtin_popcount(
                static_cast<unsigned int>(covered)
            );

        if (uncovered <= 2) {
            return memo[covered] = 1;
        }

        int answer =
            uncovered;

        for (int second = first + 1;
             second < n;
             second++) {
            if ((covered & (1 << second)) != 0) {
                continue;
            }

            answer = min(
                answer,
                1 +
                solve(
                    covered |
                    lineMask[first][second]
                )
            );
        }

        memo[covered] =
            answer;

        return memo[covered];
    }

public:
    int minimumLines(vector<vector<int>>& points) {
        n =
            static_cast<int>(points.size());

        if (n <= 2) {
            return 1;
        }

        lineMask.assign(
            n,
            vector<int>(n)
        );

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

                lineMask[first][second] =
                    mask;

                lineMask[second][first] =
                    mask;
            }
        }

        memo.assign(
            1 << n,
            -1
        );

        return solve(0);
    }
};
