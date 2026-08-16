class Solution {
    static constexpr int MOD =
        1000000007;

    vector<array<int, 26>> memo;
    vector<array<bool, 26>> visited;

    int solve(
        int remaining,
        int character
    ) {
        if (remaining == 0) {
            return 1;
        }

        if (visited[remaining][character]) {
            return memo[remaining][character];
        }

        visited[remaining][character] =
            true;

        long long answer;

        if (character == 25) {
            answer =
                solve(
                    remaining - 1,
                    0
                ) +
                solve(
                    remaining - 1,
                    1
                );
        } else {
            answer =
                solve(
                    remaining - 1,
                    character + 1
                );
        }

        memo[remaining][character] =
            static_cast<int>(
                answer %
                MOD
            );

        return memo[remaining][character];
    }

public:
    int lengthAfterTransformations(
        string s,
        int t
    ) {
        memo.assign(
            t + 1,
            {}
        );

        visited.assign(
            t + 1,
            {}
        );

        long long answer = 0;

        for (char character :
             s) {
            answer +=
                solve(
                    t,
                    character -
                    'a'
                );

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
