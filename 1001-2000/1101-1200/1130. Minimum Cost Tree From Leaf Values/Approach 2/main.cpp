class Solution {
    vector<vector<int>> maximumValue;
    vector<vector<int>> memo;

    int solve(
        const vector<int>& arr,
        int left,
        int right
    ) {
        if (left == right) {
            return 0;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int answer =
            numeric_limits<int>::max();

        for (int split = left;
             split < right;
             split++) {
            answer = min(
                answer,
                solve(
                    arr,
                    left,
                    split
                ) +
                solve(
                    arr,
                    split + 1,
                    right
                ) +
                maximumValue[left][split] *
                maximumValue[split + 1][right]
            );
        }

        memo[left][right] = answer;
        return memo[left][right];
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        int n =
            static_cast<int>(arr.size());

        maximumValue.assign(
            n,
            vector<int>(n)
        );

        for (int left = 0; left < n; left++) {
            int maximum = 0;

            for (int right = left;
                 right < n;
                 right++) {
                maximum = max(
                    maximum,
                    arr[right]
                );

                maximumValue[left][right] =
                    maximum;
            }
        }

        memo.assign(
            n,
            vector<int>(
                n,
                -1
            )
        );

        return solve(
            arr,
            0,
            n - 1
        );
    }
};
