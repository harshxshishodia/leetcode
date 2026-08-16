class Solution {
    vector<long long> memo;
    vector<bool> visited;

    long long solve(
        int point,
        int n,
        const vector<vector<vector<int>>>& starting
    ) {
        if (point >= n) {
            return 0;
        }

        if (visited[point]) {
            return memo[point];
        }

        visited[point] = true;

        long long answer =
            solve(
                point + 1,
                n,
                starting
            );

        for (const vector<int>& ride : starting[point]) {
            int end =
                ride[0];

            int tip =
                ride[1];

            answer = max(
                answer,
                end -
                point +
                tip +
                solve(
                    end,
                    n,
                    starting
                )
            );
        }

        memo[point] =
            answer;

        return memo[point];
    }

public:
    long long maxTaxiEarnings(
        int n,
        vector<vector<int>>& rides
    ) {
        vector<vector<vector<int>>> starting(
            n + 1
        );

        for (const vector<int>& ride : rides) {
            starting[ride[0]].push_back({
                ride[1],
                ride[2]
            });
        }

        memo.assign(
            n + 1,
            0
        );

        visited.assign(
            n + 1,
            false
        );

        return solve(
            1,
            n,
            starting
        );
    }
};
