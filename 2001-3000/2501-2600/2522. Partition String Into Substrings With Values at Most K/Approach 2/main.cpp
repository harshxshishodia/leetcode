class Solution {
    vector<int> memo;

    int solve(
        const string& s,
        long long k,
        int index
    ) {
        if (index ==
            static_cast<int>(s.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
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

        memo[index] =
            answer;

        return memo[index];
    }

public:
    int minimumPartition(
        string s,
        int k
    ) {
        memo.assign(
            s.size(),
            -1
        );

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
