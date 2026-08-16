class Solution {
    long long solve(
        const vector<int>& lane1,
        const vector<int>& lane2,
        int index,
        int lane,
        int switches
    ) {
        int n =
            static_cast<int>(lane1.size());

        if (index >= n) {
            return 0;
        }

        long long value =
            lane == 0
                ? lane1[index]
                : lane2[index];

        long long answer =
            value;

        answer = max(
            answer,
            value +
            solve(
                lane1,
                lane2,
                index + 1,
                lane,
                switches
            )
        );

        if (switches > 0) {
            answer = max(
                answer,
                value +
                solve(
                    lane1,
                    lane2,
                    index + 1,
                    lane ^ 1,
                    switches - 1
                )
            );

            answer = max(
                answer,
                solve(
                    lane1,
                    lane2,
                    index,
                    lane ^ 1,
                    switches - 1
                )
            );
        }

        return answer;
    }

public:
    long long maxCoins(
        vector<int>& lane1,
        vector<int>& lane2
    ) {
        long long answer =
            numeric_limits<long long>::min();

        for (int start = 0;
             start < static_cast<int>(lane1.size());
             start++) {
            answer = max(
                answer,
                solve(
                    lane1,
                    lane2,
                    start,
                    0,
                    2
                )
            );
        }

        return answer;
    }
};
