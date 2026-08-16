class Solution {
    vector<vector<long long>> memo;
    vector<vector<bool>> visited;

    long long solve(
        const vector<vector<int>>& points,
        int row,
        int previousCol
    ) {
        if (row == static_cast<int>(points.size())) {
            return 0;
        }

        if (previousCol != -1 &&
            visited[row][previousCol]) {
            return memo[row][previousCol];
        }

        long long answer =
            numeric_limits<long long>::min();

        for (int col = 0;
             col < static_cast<int>(points[0].size());
             col++) {
            long long value =
                points[row][col];

            if (previousCol != -1) {
                value -=
                    abs(col - previousCol);
            }

            value +=
                solve(
                    points,
                    row + 1,
                    col
                );

            answer = max(
                answer,
                value
            );
        }

        if (previousCol != -1) {
            visited[row][previousCol] = true;
            memo[row][previousCol] = answer;
        }

        return answer;
    }

public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows =
            static_cast<int>(points.size());

        int cols =
            static_cast<int>(points[0].size());

        memo.assign(
            rows,
            vector<long long>(cols)
        );

        visited.assign(
            rows,
            vector<bool>(cols)
        );

        return solve(
            points,
            0,
            -1
        );
    }
};
