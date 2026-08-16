class Solution {
    vector<int> memo;

    int solve(
        const vector<int>& strength,
        int K,
        int mask
    ) {
        int n =
            static_cast<int>(strength.size());

        if (mask ==
            (1 << n) -
            1) {
            return 0;
        }

        if (memo[mask] != -1) {
            return memo[mask];
        }

        int broken =
            __builtin_popcount(
                static_cast<unsigned int>(mask)
            );

        int factor =
            1 +
            broken *
            K;

        int answer =
            numeric_limits<int>::max();

        for (int index = 0;
             index < n;
             index++) {
            if ((mask & (1 << index)) != 0) {
                continue;
            }

            int minutes =
                (
                    strength[index] +
                    factor -
                    1
                ) /
                factor;

            answer = min(
                answer,
                minutes +
                solve(
                    strength,
                    K,
                    mask |
                    (1 << index)
                )
            );
        }

        memo[mask] =
            answer;

        return answer;
    }

public:
    int findMinimumTime(
        vector<int>& strength,
        int K
    ) {
        memo.assign(
            1 << strength.size(),
            -1
        );

        return solve(
            strength,
            K,
            0
        );
    }
};
