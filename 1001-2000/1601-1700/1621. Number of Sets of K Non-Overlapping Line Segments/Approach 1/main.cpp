class Solution {
    static constexpr int MOD =
        1000000007;

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

        return static_cast<int>(answer);
    }

public:
    int numberOfSets(int n, int k) {
        return solve(
            n,
            0,
            k
        );
    }
};
