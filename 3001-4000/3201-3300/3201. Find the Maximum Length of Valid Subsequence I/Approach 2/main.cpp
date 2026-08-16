class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<array<int, 2>> dp(
            n
        );

        int answer = 1;

        for (int index = 0;
             index < n;
             index++) {
            dp[index][0] =
                1;

            dp[index][1] =
                1;

            for (int previous = 0;
                 previous < index;
                 previous++) {
                int target =
                    (
                        nums[previous] +
                        nums[index]
                    ) %
                    2;

                dp[index][target] = max(
                    dp[index][target],
                    dp[previous][target] +
                    1
                );
            }

            answer = max({
                answer,
                dp[index][0],
                dp[index][1]
            });
        }

        return answer;
    }
};
