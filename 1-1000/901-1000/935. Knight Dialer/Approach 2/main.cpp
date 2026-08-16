class Solution {
    static constexpr int MOD = 1000000007;
    vector<array<long long, 10>> memo;
    vector<array<bool, 10>> visited;

    long long solve(
        int digit,
        int remaining
    ) {
        if (remaining == 1) {
            return 1;
        }

        if (visited[remaining][digit]) {
            return memo[remaining][digit];
        }

        visited[remaining][digit] = true;

        static const vector<vector<int>> next = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        long long answer = 0;

        for (int nextDigit : next[digit]) {
            answer += solve(
                nextDigit,
                remaining - 1
            );

            answer %= MOD;
        }

        memo[remaining][digit] = answer;
        return memo[remaining][digit];
    }

public:
    int knightDialer(int n) {
        memo.assign(
            n + 1,
            {}
        );

        visited.assign(
            n + 1,
            {}
        );

        long long answer = 0;

        for (int digit = 0; digit <= 9; digit++) {
            answer += solve(
                digit,
                n
            );

            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
