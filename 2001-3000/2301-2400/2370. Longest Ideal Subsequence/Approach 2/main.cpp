class Solution {
    vector<array<int, 27>> memo;
    vector<array<bool, 27>> visited;

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

        if (visited[index][previous]) {
            return memo[index][previous];
        }

        visited[index][previous] = true;

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

        memo[index][previous] = max(
            skip,
            take
        );

        return memo[index][previous];
    }

public:
    int longestIdealString(
        string s,
        int k
    ) {
        memo.assign(
            s.size(),
            {}
        );

        visited.assign(
            s.size(),
            {}
        );

        return solve(
            s,
            k,
            0,
            26
        );
    }
};
