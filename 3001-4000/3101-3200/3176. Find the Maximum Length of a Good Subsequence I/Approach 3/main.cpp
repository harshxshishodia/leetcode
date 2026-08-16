class Solution {
public:
    int maximumLength(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(
                nums.size()
            );

        vector<vector<int>> dp(
            n,
            vector<int>(
                k + 1,
                1
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
                    nums[index] !=
                    nums[previous];

                for (int changes =
                         difference;
                     changes <= k;
                     changes++) {
                    dp[index][changes] = max(
                        dp[index][changes],
                        dp[previous][
                            changes -
                            difference
                        ] +
                        1
                    );
                }
            }

            for (int changes = 0;
                 changes <= k;
                 changes++) {
                answer = max(
                    answer,
                    dp[index][changes]
                );
            }
        }

        return answer;
    }
};
