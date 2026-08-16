class Solution {
public:
    int maxResult(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> dp(n);
        deque<int> candidates;

        dp[0] = nums[0];
        candidates.push_back(0);

        for (int index = 1;
             index < n;
             index++) {
            while (!candidates.empty() &&
                   candidates.front() <
                   index - k) {
                candidates.pop_front();
            }

            dp[index] =
                nums[index] +
                dp[candidates.front()];

            while (!candidates.empty() &&
                   dp[candidates.back()] <=
                   dp[index]) {
                candidates.pop_back();
            }

            candidates.push_back(index);
        }

        return dp[n - 1];
    }
};
