class Solution {
    vector<array<int, 4>> memo;
    vector<array<bool, 4>> visited;

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

        if (visited[position][lane]) {
            return memo[position][lane];
        }

        visited[position][lane] = true;

        int answer;

        if (obstacles[position + 1] != lane) {
            answer = solve(
                obstacles,
                position + 1,
                lane
            );
        } else {
            answer =
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
        }

        memo[position][lane] =
            answer;

        return memo[position][lane];
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        memo.assign(
            obstacles.size(),
            {}
        );

        visited.assign(
            obstacles.size(),
            {}
        );

        return solve(
            obstacles,
            0,
            2
        );
    }
};
