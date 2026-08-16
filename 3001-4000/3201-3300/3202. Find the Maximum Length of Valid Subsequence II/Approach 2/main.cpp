class Solution {
public:
    int maximumLength(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<vector<int>> dp(
            n,
            vector<int>(
                k,
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
                int target =
                    (
                        nums[previous] +
                        nums[index]
                    ) %
                    k;

                dp[index][target] = max(
                    dp[index][target],
                    dp[previous][target] +
                    1
                );

                answer = max(
                    answer,
                    dp[index][target]
                );
            }
        }

        return answer;
    }
};
