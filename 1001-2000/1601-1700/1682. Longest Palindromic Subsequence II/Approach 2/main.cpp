class Solution {
    vector<vector<array<int, 27>>> memo;
    vector<vector<array<bool, 27>>> visited;

    int solve(
        const string& s,
        int left,
        int right,
        int previous
    ) {
        if (left >= right) {
            return 0;
        }

        if (visited[left][right][previous]) {
            return memo[left][right][previous];
        }

        visited[left][right][previous] = true;

        int answer = max(
            solve(
                s,
                left + 1,
                right,
                previous
            ),
            solve(
                s,
                left,
                right - 1,
                previous
            )
        );

        int current =
            s[left] - 'a';

        if (s[left] == s[right] &&
            current != previous) {
            answer = max(
                answer,
                2 +
                solve(
                    s,
                    left + 1,
                    right - 1,
                    current
                )
            );
        }

        memo[left][right][previous] =
            answer;

        return memo[left][right][previous];
    }

public:
    int longestPalindromeSubseq(string s) {
        int n =
            static_cast<int>(s.size());

        memo.assign(
            n,
            vector<array<int, 27>>(
                n
            )
        );

        visited.assign(
            n,
            vector<array<bool, 27>>(
                n
            )
        );

        return solve(
            s,
            0,
            n - 1,
            26
        );
    }
};
