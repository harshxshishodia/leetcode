class Solution {
    int solve(
        const vector<int>& obstacles,
        int position,
        int lane
    ) {
        int n =
            static_cast<int>(obstacles.size());

        if (position == n - 1) {
            return 0;
        }

        if (obstacles[position + 1] != lane) {
            return solve(
                obstacles,
                position + 1,
                lane
            );
        }

        int answer =
            numeric_limits<int>::max() / 4;

        for (int nextLane = 1;
             nextLane <= 3;
             nextLane++) {
            if (nextLane == lane ||
                obstacles[position] ==
                nextLane) {
                continue;
            }

            answer = min(
                answer,
                1 +
                solve(
                    obstacles,
                    position,
                    nextLane
                )
            );
        }

        return answer;
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(
            obstacles,
            0,
            2
        );
    }
};
