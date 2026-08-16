class Solution {
    int solve(
        const string& text1,
        const string& text2,
        int first,
        int second
    ) {
        if (first == static_cast<int>(text1.size()) ||
            second == static_cast<int>(text2.size())) {
            return 0;
        }

        if (text1[first] == text2[second]) {
            return 1 +
                   solve(
                       text1,
                       text2,
                       first + 1,
                       second + 1
                   );
        }

        return max(
            solve(
                text1,
                text2,
                first + 1,
                second
            ),
            solve(
                text1,
                text2,
                first,
                second + 1
            )
        );
    }

public:
    int longestCommonSubsequence(
        string text1,
        string text2
    ) {
        return solve(
            text1,
            text2,
            0,
            0
        );
    }
};
