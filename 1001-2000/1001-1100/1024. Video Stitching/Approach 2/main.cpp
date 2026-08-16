class Solution {
    static constexpr int INF = 1000000000;

    int solve(
        const vector<vector<int>>& clips,
        int time,
        int covered,
        vector<int>& memo
    ) {
        if (covered >= time) {
            return 0;
        }

        if (memo[covered] != -1) {
            return memo[covered];
        }

        int answer = INF;

        for (const vector<int>& clip : clips) {
            if (clip[0] > covered ||
                clip[1] <= covered) {
                continue;
            }

            answer = min(
                answer,
                1 + solve(
                    clips,
                    time,
                    min(
                        clip[1],
                        time
                    ),
                    memo
                )
            );
        }

        memo[covered] = answer;
        return memo[covered];
    }

public:
    int videoStitching(
        vector<vector<int>>& clips,
        int time
    ) {
        vector<int> memo(
            time + 1,
            -1
        );

        int answer = solve(
            clips,
            time,
            0,
            memo
        );

        return answer >= INF
            ? -1
            : answer;
    }
};
