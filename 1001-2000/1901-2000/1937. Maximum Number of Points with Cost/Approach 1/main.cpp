class Solution {
    long long solve(
        const vector<vector<int>>& points,
        int row,
        int previousCol
    ) {
        if (row == static_cast<int>(points.size())) {
            return 0;
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

        return answer;
    }

public:
    long long maxPoints(vector<vector<int>>& points) {
        return solve(
            points,
            0,
            -1
        );
    }
};
