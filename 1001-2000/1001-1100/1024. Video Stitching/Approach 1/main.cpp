class Solution {
    static constexpr int INF = 1000000000;

    int solve(
        const vector<vector<int>>& clips,
        int time,
        int covered
    ) {
        if (covered >= time) {
            return 0;
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
                    clip[1]
                )
            );
        }

        return answer;
    }

public:
    int videoStitching(
        vector<vector<int>>& clips,
        int time
    ) {
        int answer = solve(
            clips,
            time,
            0
        );

        return answer >= INF
            ? -1
            : answer;
    }
};
