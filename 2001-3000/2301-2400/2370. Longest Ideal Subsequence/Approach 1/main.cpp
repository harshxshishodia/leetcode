class Solution {
    int solve(
        const string& s,
        int k,
        int index,
        int previous
    ) {
        if (index ==
            static_cast<int>(s.size())) {
            return 0;
        }

        int skip =
            solve(
                s,
                k,
                index + 1,
                previous
            );

        int current =
            s[index] - 'a';

        int take = 0;

        if (previous == 26 ||
            abs(
                current -
                previous
            ) <= k) {
            take =
                1 +
                solve(
                    s,
                    k,
                    index + 1,
                    current
                );
        }

        return max(
            skip,
            take
        );
    }

public:
    int longestIdealString(
        string s,
        int k
    ) {
        return solve(
            s,
            k,
            0,
            26
        );
    }
};
