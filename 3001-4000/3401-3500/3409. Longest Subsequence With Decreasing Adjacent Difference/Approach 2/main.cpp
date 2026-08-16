class Solution {
    vector<vector<int>> exact;
    vector<vector<int>> suffix;

public:
    int longestSubsequence(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        const int MAX_VALUE =
            300;

        const int MAX_DIFF =
            300;

        vector<vector<int>> dp(
            n,
            vector<int>(
                MAX_DIFF + 1
            )
        );

        vector<vector<int>> bestAtLeast(
            n,
            vector<int>(
                MAX_DIFF + 2
            )
        );

        int answer = 1;

        for (int index = 0;
             index < n;
             index++) {
            for (int previous = 0;
                 previous < index;
                 previous++) {
                int difference =
                    abs(
                        nums[index] -
                        nums[previous]
                    );

                dp[index][difference] = max(
                    dp[index][difference],
                    max(
                        2,
                        bestAtLeast[previous][difference] +
                        1
                    )
                );
            }

            for (int difference = MAX_DIFF;
                 difference >= 0;
                 difference--) {
                bestAtLeast[index][difference] = max(
                    dp[index][difference],
                    bestAtLeast[index][difference + 1]
                );
            }

            answer = max(
                answer,
                bestAtLeast[index][0]
            );
        }

        return answer;
    }
};
