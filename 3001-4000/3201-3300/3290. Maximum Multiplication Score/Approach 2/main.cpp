class Solution {
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

        return max(
            skip,
            take
        );
    }

public:
    long long maxScore(
        vector<int>& a,
        vector<int>& b
    ) {
        return solve(
            a,
            b,
            0,
            0
        );
    }
};
