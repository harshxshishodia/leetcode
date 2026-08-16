class Solution {
    static constexpr int MOD =
        1000000007;

    vector<vector<int>> memo;

    int solve(
        int n,
        int start,
        int segments
    ) {
        if (segments == 0) {
            return 1;
        }

        if (start >= n - 1) {
            return 0;
        }

        if (memo[start][segments] != -1) {
            return memo[start][segments];
        }

        long long answer = 0;

        for (int left = start;
             left < n - 1;
             left++) {
            for (int right = left + 1;
                 right < n;
                 right++) {
                answer +=
                    solve(
                        n,
                        right,
                        segments - 1
                    );

                answer %= MOD;
            }
        }

        memo[start][segments] =
            static_cast<int>(answer);

        return memo[start][segments];
    }

public:
    int numberOfSets(int n, int k) {
        memo.assign(
            n,
            vector<int>(
                k + 1,
                -1
            )
        );

        return solve(
            n,
            0,
            k
        );
    }
};
