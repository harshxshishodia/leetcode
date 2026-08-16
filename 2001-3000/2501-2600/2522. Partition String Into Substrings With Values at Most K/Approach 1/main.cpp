class Solution {
    int solve(
        const string& s,
        long long k,
        int index
    ) {
        if (index ==
            static_cast<int>(s.size())) {
            return 0;
        }

        const int INF =
            1000000000;

        long long value = 0;
        int answer = INF;

        for (int end = index;
             end < static_cast<int>(s.size());
             end++) {
            value =
                value *
                10 +
                (
                    s[end] -
                    '0'
                );

            if (value > k) {
                break;
            }

            int next =
                solve(
                    s,
                    k,
                    end + 1
                );

            if (next != INF) {
                answer = min(
                    answer,
                    1 + next
                );
            }
        }

        return answer;
    }

public:
    int minimumPartition(
        string s,
        int k
    ) {
        const int INF =
            1000000000;

        int answer =
            solve(
                s,
                k,
                0
            );

        return answer == INF
            ? -1
            : answer;
    }
};
