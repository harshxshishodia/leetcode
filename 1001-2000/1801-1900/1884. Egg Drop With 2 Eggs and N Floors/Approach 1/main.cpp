class Solution {
    int solve(int floors) {
        if (floors <= 1) {
            return floors;
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

        return answer;
    }

public:
    int twoEggDrop(int n) {
        return solve(n);
    }
};
