class Solution {
public:
    int longestCommonSubsequence(
        string text1,
        string text2
    ) {
        if (text1.size() < text2.size()) {
            swap(
                text1,
                text2
            );
        }

        int firstLength =
            static_cast<int>(text1.size());

        int secondLength =
            static_cast<int>(text2.size());

        vector<int> dp(
            secondLength + 1
        );

        for (int first = 1; first <= firstLength; first++) {
            int diagonal = 0;

            for (int second = 1; second <= secondLength; second++) {
                int previous =
                    dp[second];

                if (text1[first - 1] == text2[second - 1]) {
                    dp[second] =
                        diagonal + 1;
                } else {
                    dp[second] = max(
                        dp[second],
                        dp[second - 1]
                    );
                }

                diagonal = previous;
            }
        }

        return dp[secondLength];
    }
};
