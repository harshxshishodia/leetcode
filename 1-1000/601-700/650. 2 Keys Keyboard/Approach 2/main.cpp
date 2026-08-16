class Solution {
    static constexpr int INF = 1000000000;

    int solve(
        int screen,
        int clipboard,
        int target,
        vector<vector<int>>& memo
    ) {
        if (screen == target) {
            return 0;
        }

        if (screen > target) {
            return INF;
        }

        if (memo[screen][clipboard] != -1) {
            return memo[screen][clipboard];
        }

        int answer = INF;

        if (clipboard > 0 &&
            screen + clipboard <= target) {
            answer = min(
                answer,
                1 + solve(
                    screen + clipboard,
                    clipboard,
                    target,
                    memo
                )
            );
        }

        if (clipboard != screen &&
            screen * 2 <= target) {
            answer = min(
                answer,
                1 + solve(
                    screen,
                    screen,
                    target,
                    memo
                )
            );
        }

        memo[screen][clipboard] = answer;
        return memo[screen][clipboard];
    }

public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        vector<vector<int>> memo(
            n + 1,
            vector<int>(n + 1, -1)
        );

        return solve(
            1,
            0,
            n,
            memo
        );
    }
};
