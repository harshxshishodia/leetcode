class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maximum =
            *max_element(
                nums.begin(),
                nums.end()
            );

        vector<int> points(maximum + 1);

        for (int number : nums) {
            points[number] += number;
        }

        vector<int> dp(maximum + 1);
        dp[0] = 0;

        if (maximum >= 1) {
            dp[1] = points[1];
        }

        for (int value = 2; value <= maximum; value++) {
            dp[value] = max(
                dp[value - 1],
                dp[value - 2] + points[value]
            );
        }

        return dp[maximum];
    }
};
