class Solution {
public:
    int findMinimumTime(
        vector<int>& strength,
        int K
    ) {
        int n =
            static_cast<int>(strength.size());

        vector<vector<int>> cost(
            n + 1,
            vector<int>(
                n + 1
            )
        );

        for (int lock = 1;
             lock <= n;
             lock++) {
            for (int position = 1;
                 position <= n;
                 position++) {
                int factor =
                    1 +
                    (
                        position -
                        1
                    ) *
                    K;

                cost[lock][position] =
                    (
                        strength[lock - 1] +
                        factor -
                        1
                    ) /
                    factor;
            }
        }

        vector<int> u(
            n + 1
        );

        vector<int> v(
            n + 1
        );

        vector<int> p(
            n + 1
        );

        vector<int> way(
            n + 1
        );

        for (int lock = 1;
             lock <= n;
             lock++) {
            p[0] =
                lock;

            int column = 0;

            vector<int> minimum(
                n + 1,
                numeric_limits<int>::max()
            );

            vector<bool> used(
                n + 1
            );

            do {
                used[column] =
                    true;

                int row =
                    p[column];

                int delta =
                    numeric_limits<int>::max();

                int nextColumn =
                    0;

                for (int candidate = 1;
                     candidate <= n;
                     candidate++) {
                    if (used[candidate]) {
                        continue;
                    }

                    int current =
                        cost[row][candidate] -
                        u[row] -
                        v[candidate];

                    if (current <
                        minimum[candidate]) {
                        minimum[candidate] =
                            current;

                        way[candidate] =
                            column;
                    }

                    if (minimum[candidate] <
                        delta) {
                        delta =
                            minimum[candidate];

                        nextColumn =
                            candidate;
                    }
                }

                for (int candidate = 0;
                     candidate <= n;
                     candidate++) {
                    if (used[candidate]) {
                        u[p[candidate]] +=
                            delta;

                        v[candidate] -=
                            delta;
                    } else {
                        minimum[candidate] -=
                            delta;
                    }
                }

                column =
                    nextColumn;
            } while (p[column] != 0);

            do {
                int previous =
                    way[column];

                p[column] =
                    p[previous];

                column =
                    previous;
            } while (column != 0);
        }

        return -v[0];
    }
};
