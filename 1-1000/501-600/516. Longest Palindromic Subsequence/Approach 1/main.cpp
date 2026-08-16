class Solution {
    int solve(
        const string& s,
        int left,
        int right
    ) {
        if (left > right) {
            return 0;
        }

        if (left == right) {
            return 1;
        }

        if (s[left] == s[right]) {
            return 2 + solve(
                s,
                left + 1,
                right - 1
            );
        }

        return max(
            solve(s, left + 1, right),
            solve(s, left, right - 1)
        );
    }

public:
    int longestPalindromeSubseq(string s) {
        return solve(
            s,
            0,
            static_cast<int>(s.size()) - 1
        );
    }
};
