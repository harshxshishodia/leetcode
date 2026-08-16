class Solution {
    int solve(
        const string& s,
        int left,
        int right,
        int previous
    ) {
        if (left >= right) {
            return 0;
        }

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

        return answer;
    }

public:
    int longestPalindromeSubseq(string s) {
        return solve(
            s,
            0,
            static_cast<int>(s.size()) - 1,
            26
        );
    }
};
