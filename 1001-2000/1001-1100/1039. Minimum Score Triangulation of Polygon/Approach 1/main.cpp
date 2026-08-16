class Solution {
    int solve(
        const vector<int>& values,
        int left,
        int right
    ) {
        if (right - left < 2) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        for (int middle = left + 1;
             middle < right;
             middle++) {
            answer = min(
                answer,
                values[left] *
                values[middle] *
                values[right] +
                solve(
                    values,
                    left,
                    middle
                ) +
                solve(
                    values,
                    middle,
                    right
                )
            );
        }

        return answer;
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        return solve(
            values,
            0,
            static_cast<int>(values.size()) - 1
        );
    }
};
