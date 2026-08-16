class Solution {
    vector<int> memo;

    int solve(int floors) {
        if (floors <= 1) {
            return floors;
        }

        if (memo[floors] != -1) {
            return memo[floors];
        }

        int answer =
            numeric_limits<int>::max();

        for (int floor = 1;
             floor <= floors;
             floor++) {
            int breaks =
                floor - 1;

            int survives =
                solve(
                    floors - floor
                );

            answer = min(
                answer,
                1 +
                max(
                    breaks,
                    survives
                )
            );
        }

        memo[floors] = answer;
        return memo[floors];
    }

public:
    int twoEggDrop(int n) {
        memo.assign(
            n + 1,
            -1
        );

        return solve(n);
    }
};
