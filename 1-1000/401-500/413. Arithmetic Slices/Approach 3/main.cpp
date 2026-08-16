class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        if (n < 3) {
            return 0;
        }

        vector<int> dp(n);
        int answer = 0;

        for (int i = 2; i < n; i++) {
            if (static_cast<long long>(nums[i]) -
                nums[i - 1] ==
                static_cast<long long>(nums[i - 1]) -
                nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                answer += dp[i];
            }
        }

        return answer;
    }
};
