class Solution {
    vector<array<long long, 5>> memo;
    vector<array<bool, 5>> visited;

    long long solve(
        const vector<int>& a,
        const vector<int>& b,
        int index,
        int picked
    ) {
        if (picked == 4) {
            return 0;
        }

        if (index ==
            static_cast<int>(b.size())) {
            return
                numeric_limits<long long>::min() /
                4;
        }

        if (visited[index][picked]) {
            return memo[index][picked];
        }

        visited[index][picked] =
            true;

        long long skip =
            solve(
                a,
                b,
                index + 1,
                picked
            );

        long long next =
            solve(
                a,
                b,
                index + 1,
                picked + 1
            );

        long long take =
            numeric_limits<long long>::min() /
            4;

        if (next >
            numeric_limits<long long>::min() /
            8) {
            take =
                1LL *
                a[picked] *
                b[index] +
                next;
        }

        memo[index][picked] = max(
            skip,
            take
        );

        return memo[index][picked];
    }

public:
    long long maxScore(
        vector<int>& a,
        vector<int>& b
    ) {
        memo.assign(
            b.size(),
            {}
        );

        visited.assign(
            b.size(),
            {}
        );

        return solve(
            a,
            b,
            0,
            0
        );
    }
};
