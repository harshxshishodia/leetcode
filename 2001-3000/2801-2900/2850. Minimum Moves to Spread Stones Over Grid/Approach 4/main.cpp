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

        int n =
            static_cast<int>(extra.size());

        if (n == 0) {
            return 0;
        }

        vector<vector<int>> cost(
            n + 1,
            vector<int>(
                n + 1
            )
        );

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cost[i][j] =
                    abs(
                        extra[i - 1].first -
                        empty[j - 1].first
                    ) +
                    abs(
                        extra[i - 1].second -
                        empty[j - 1].second
                    );
            }
        }

        vector<int> u(n + 1);
        vector<int> v(n + 1);
        vector<int> p(n + 1);
        vector<int> way(n + 1);

        for (int i = 1; i <= n; i++) {
            p[0] = i;
            int j0 = 0;

            vector<int> minimum(
                n + 1,
                numeric_limits<int>::max()
            );

            vector<bool> used(
                n + 1
            );

            do {
                used[j0] = true;
                int i0 = p[j0];
                int delta =
                    numeric_limits<int>::max();

                int j1 = 0;

                for (int j = 1; j <= n; j++) {
                    if (used[j]) {
                        continue;
                    }

                    int current =
                        cost[i0][j] -
                        u[i0] -
                        v[j];

                    if (current <
                        minimum[j]) {
                        minimum[j] =
                            current;

                        way[j] =
                            j0;
                    }

                    if (minimum[j] <
                        delta) {
                        delta =
                            minimum[j];

                        j1 =
                            j;
                    }
                }

                for (int j = 0; j <= n; j++) {
                    if (used[j]) {
                        u[p[j]] +=
                            delta;

                        v[j] -=
                            delta;
                    } else {
                        minimum[j] -=
                            delta;
                    }
                }

                j0 =
                    j1;
            } while (p[j0] != 0);

            do {
                int j1 =
                    way[j0];

                p[j0] =
                    p[j1];

                j0 =
                    j1;
            } while (j0 != 0);
        }

        return -v[0];
    }
};
