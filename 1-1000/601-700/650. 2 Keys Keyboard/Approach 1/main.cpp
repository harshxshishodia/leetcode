class Solution {
    static constexpr int INF = 1000000000;

    int solve(
        int screen,
        int clipboard,
        int target
    ) {
        if (screen == target) {
            return 0;
        }

        if (screen > target) {
            return INF;
        }

        int answer = INF;

        if (clipboard > 0 &&
            screen + clipboard <= target) {
            answer = min(
                answer,
                1 + solve(
                    screen + clipboard,
                    clipboard,
                    target
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
                    target
                )
            );
        }

        return answer;
    }

public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        return solve(1, 0, n);
    }
};
