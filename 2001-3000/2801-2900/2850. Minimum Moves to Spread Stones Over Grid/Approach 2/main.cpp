class Solution {
    vector<pair<int, int>> extra;
    vector<pair<int, int>> empty;
    vector<bool> used;

    int solve(int index) {
        if (index ==
            static_cast<int>(extra.size())) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        for (int target = 0;
             target < static_cast<int>(empty.size());
             target++) {
            if (used[target]) {
                continue;
            }

            used[target] = true;

            int distance =
                abs(
                    extra[index].first -
                    empty[target].first
                ) +
                abs(
                    extra[index].second -
                    empty[target].second
                );

            answer = min(
                answer,
                distance +
                solve(
                    index + 1
                )
            );

            used[target] = false;
        }

        return answer;
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {
        extra.clear();
        empty.clear();

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

        used.assign(
            empty.size(),
            false
        );

        return solve(0);
    }
};
