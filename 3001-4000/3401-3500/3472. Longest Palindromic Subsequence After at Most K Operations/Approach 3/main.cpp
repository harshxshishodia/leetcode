class Solution {
    vector<vector<vector<int>>> memo;

    int pairCost(
        char first,
        char second
    ) {
        int difference =
            abs(
                first -
                second
            );

        return min(
            difference,
            26 -
            difference
        );
    }

    int solve(
        const string& s,
        int left,
        int right,
        int remaining
    ) {
        if (left > right) {
            return 0;
        }

        if (left == right) {
            return 1;
        }

        int& answer =
            memo[left][right][remaining];

        if (answer != -1) {
            return answer;
        }

        answer = max(
            solve(
                s,
                left + 1,
                right,
                remaining
            ),
            solve(
                s,
                left,
                right - 1,
                remaining
            )
        );

        int cost =
            pairCost(
                s[left],
                s[right]
            );

        if (cost <= remaining) {
            answer = max(
                answer,
                2 +
                solve(
                    s,
                    left + 1,
                    right - 1,
                    remaining -
                    cost
                )
            );
        }

        return answer;
    }

public:
    int longestPalindromicSubsequence(
        string s,
        int k
    ) {
        int n =
            static_cast<int>(s.size());

        memo.assign(
            n,
            vector<vector<int>>(
                n,
                vector<int>(
                    k + 1,
                    -1
                )
            )
        );

        return solve(
            s,
            0,
            n - 1,
            k
        );
    }
};
