class Solution {
    long long solve(
        int point,
        int n,
        const vector<vector<vector<int>>>& starting
    ) {
        if (point >= n) {
            return 0;
        }

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

        return answer;
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

        return solve(
            1,
            n,
            starting
        );
    }
};
